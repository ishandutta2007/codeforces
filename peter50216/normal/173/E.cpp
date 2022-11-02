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
int ri[101000],ai[101000];
int que[101000][2];
int qa[101000];
int qs;
int n,k;
struct XD{
    int x,y,k,id;
    bool operator<(const XD& b)const{
        return x==b.x?y==b.y?k<b.k:y<b.y:x<b.x;
    }
    XD(int xx=0,int yy=0,int kk=0,int ii=0):x(xx),y(yy),k(kk),id(ii){}
};
int sc[101000];
XD ev[301000];
int ec;
int tre[301000];
int yc;
int ys[501000];
inline void treadd(int np,int c){
    for(;np<=yc;np+=np&-np)tre[np]+=c;
}
inline int treque(int np){
    int s=0;
    for(;np;np-=np&-np)s+=tre[np];
    return s;
}
inline void solvesc(){
    int i,j;
    ec=0;
    for(i=0;i<n;i++){
        ev[ec++]=XD(ri[i],ai[i],0,i);
        ev[ec++]=XD(ri[i],ai[i]+k,1,i);
        ev[ec++]=XD(ri[i],ai[i]-k-1,2,i);
    }
    sort(ev,ev+ec);
    yc=0;
    for(i=0;i<ec;i++){
        ys[yc++]=ev[i].y;
    }
    sort(ys,ys+yc);
    yc=unique(ys,ys+yc)-ys;
    for(i=0;i<ec;i++)ev[i].y=(lower_bound(ys,ys+yc,ev[i].y)-ys)+1;
    for(i=0;i<ec;i++){
        if(ev[i].k==0)treadd(ev[i].y,1);
        else if(ev[i].k==1){
            sc[ev[i].id]+=treque(ev[i].y);
        }else sc[ev[i].id]-=treque(ev[i].y);
    }
}
struct XDD{
    int x,k,v1,v2,id;
    bool operator<(const XDD& b)const{
        return x==b.x?k==b.k?v1<b.v1:k<b.k:x>b.x;
    }
    XDD(int xx=0,int kk=0,int vv1=0,int vv2=0,int ii=0):x(xx),k(kk),v1(vv1),v2(vv2),id(ii){}
};
XDD ev2[501000];
int segt[1050000];
inline void addt(int np,int l,int r,int x,int c){
    if(l==r){
        segt[np]=max(segt[np],c);
        return;
    }
    int m=(l+r)/2;
    if(x<=m)addt(np*2,l,m,x,c);
    else addt(np*2+1,m+1,r,x,c);
    segt[np]=max(segt[np*2],segt[np*2+1]);
}
inline int quet(int np,int l,int r,int x,int y){
    if(l==x&&r==y){
        return segt[np];
    }
    int m=(l+r)/2;
    if(y<=m)return quet(np*2,l,m,x,y);
    else if(x>m)return quet(np*2+1,m+1,r,x,y);
    else return max(quet(np*2,l,m,x,m),quet(np*2+1,m+1,r,m+1,y));
}
inline void solveans(){
    ec=0;
    int i;
    for(i=0;i<n;i++){
        ev2[ec++]=XDD(ri[i],0,ai[i],sc[i]);
    }
    for(i=0;i<qs;i++){
        int x=que[i][0],y=que[i][1];
        int maxa=max(ai[x],ai[y]),mina=min(ai[x],ai[y]);
        if(maxa-k>mina+k){
            qa[i]=-1;
            continue;
        }
        int maxr=max(ri[x],ri[y]);
        ev2[ec++]=XDD(maxr,1,maxa-k,mina+k,i);
    }
    sort(ev2,ev2+ec);
    yc=0;
    for(i=0;i<ec;i++){
        ys[yc++]=ev2[i].v1;
        if(ev2[i].k!=0)ys[yc++]=ev2[i].v2;
    }
    sort(ys,ys+yc);
    yc=unique(ys,ys+yc)-ys;
    for(i=0;i<ec;i++){
        ev2[i].v1=(lower_bound(ys,ys+yc,ev2[i].v1)-ys)+1;
        if(ev2[i].k!=0){
            ev2[i].v2=(lower_bound(ys,ys+yc,ev2[i].v2)-ys)+1;
        }
    }
    for(i=0;i<ec;i++){
        if(ev2[i].k==0){
            addt(1,1,yc,ev2[i].v1,ev2[i].v2);
        }else{
            qa[ev2[i].id]=quet(1,1,yc,ev2[i].v1,ev2[i].v2);
            if(qa[ev2[i].id]==0)qa[ev2[i].id]=-1;
        }
    }
}
inline void solve(){
    solvesc();
    solveans();
}
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",&ri[i]);
    for(i=0;i<n;i++)scanf("%d",&ai[i]);
    scanf("%d",&qs);
    for(i=0;i<qs;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        que[i][0]=a;que[i][1]=b;
    }
    solve();
    for(i=0;i<qs;i++)printf("%d\n",qa[i]);
}