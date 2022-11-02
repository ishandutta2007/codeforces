#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int q;
long long g,r;
long long gr;
long long li[101000];
long long sl[101000];
long long qu[101000];
long long ans[101000];
long long dp[101000];
long long ev[201000];
inline long long mod(long long a,long long b){
    a%=b;
    if(a<0)a+=b;
    return a;
}
long long tre[1010000];
inline void down(int np){
    if(tre[np]!=-1){
        tre[np*2]=tre[np*2+1]=tre[np];
        tre[np]=-1;
    }
}
inline void add(int np,int l,int r,int x,int y,int c){
//    printf("add %d %d %d %d %d %d\n",np,l,r,x,y,c);
    if(x==y)return;
    if(l==x&&r==y){
        tre[np]=c;
        return;
    }
    down(np);
    int m=(l+r)/2;
    if(x<=m&&y>=m){
        add(np*2,l,m,x,m,c);
        add(np*2+1,m,r,m,y,c);
    }else if(x>=m){
        add(np*2+1,m,r,x,y,c);
    }else{
        add(np*2,l,m,x,y,c);
    }
}
inline int que(int np,int l,int r,int x){
    if(tre[np]!=-1)return tre[np];
    if(r==l+1)return tre[np];
    down(np);
    int m=(l+r)/2;
    if(x>=m)return que(np*2+1,m,r,x);
    else return que(np*2,l,m,x);
}
int evc;
inline int lshua(int x){
    return upper_bound(ev,ev+evc,x)-ev-1;
}
inline void build(){
    int i;
    memset(tre,-1,sizeof(tre));
    evc=0;
    ev[evc++]=0;
    for(i=0;i<n;i++){
        ev[evc++]=mod(g-sl[i],gr);
        ev[evc++]=mod(g+r-sl[i],gr);
    }
    sort(ev,ev+evc);
    evc=unique(ev,ev+evc)-ev;
    //printf("evc=%d\n",evc);
    //for(i=0;i<evc;i++)printf("%d ",ev[i]);puts("");
    dp[n]=0;
    for(i=n-1;i>=0;i--){
        long long sp=mod(0-sl[i],gr);
        int k=que(1,0,evc,lshua(sp));
        if(k==-1)dp[i]=sl[n]-sl[i];
        else{
            long long qq=sl[k]-sl[i];
            qq=(qq/gr+1)*gr;
            qq+=dp[k];
            dp[i]=qq;
        }
        //printf("dp[%d]=%d\n",i,dp[i]);
        long long e1=mod(g-sl[i],gr);
        long long e2=mod(g+r-sl[i],gr);
        int ee1=lshua(e1);
        int ee2=lshua(e2);
        if(ee1<ee2)add(1,0,evc,ee1,ee2,i);
        else{
            add(1,0,evc,ee1,evc,i);
            add(1,0,evc,0,ee2,i);
        }
    }
}
inline void solve(){
    int i;
    build();
    for(i=0;i<q;i++){
        long long qq=qu[i];
        long long rr=qq/gr;
        qq%=gr;
        int qqq=lshua(qq);
        int k=que(1,0,evc,qqq);
        //printf("qq=%I64d qqq=%d k=%d\n",qq,qqq,k);
        if(k==-1)ans[i]=qu[i]+sl[n];
        else{
            qq+=sl[k];
            qq=(qq/gr+1)*gr;
            qq+=dp[k];
            ans[i]=qq+rr*gr;
        }
    }
}
int main(){
    int i;
    scanf("%d%I64d%I64d",&n,&g,&r);
    gr=g+r;
    for(i=0;i<=n;i++){
        scanf("%I64d",&li[i]);
        sl[i]=li[i];
        if(i)sl[i]+=sl[i-1];
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)scanf("%I64d",&qu[i]);
    solve();
    for(i=0;i<q;i++)printf("%I64d\n",ans[i]);
}