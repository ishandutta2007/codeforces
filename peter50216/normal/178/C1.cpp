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
int tre[1050000];
int pts[201000];
inline int gcd(int a,int b){if(b)while((a%=b)&&(b%=a));return a+b;}
map<int,int> ha;
int h;
int r;
int n;
inline int que(int np,int l,int r,int x,int y){
    if(l==x&&r==y)return tre[np];
    int m=(l+r)/2;
    if(x<=m&&y>m)return que(np*2,l,m,x,m)+que(np*2+1,m+1,r,m+1,y);
    else if(y<=m)return que(np*2,l,m,x,y);
    else return que(np*2+1,m+1,r,x,y);
}
inline void add(int np,int l,int r,int x,int c){
    if(l==r){
        tre[np]+=c;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)add(np*2,l,m,x,c);
    else add(np*2+1,m+1,r,x,c);
    tre[np]=tre[np*2]+tre[np*2+1];
}
inline int find(int np,int l,int r,int x){
    //printf("find %d %d %d %d\n",np,l,r,x);
    if(l==x&&tre[np]==r-l+1)return -1;
    if(l==r){
        if(tre[np]==1)return -1;
        return l;
    }
    int m=(l+r)/2;
    if(x>m)return find(np*2+1,m+1,r,x);
    else{
        int c=find(np*2,l,m,x);
        if(c!=-1)return c;
        return find(np*2+1,m+1,r,m+1);
    }
}
inline int solve(int hh,int id){
    //printf("solve hh=%d id=%d\n",hh,id);
    int blo=hh/n;
    int to,dis;
    if(que(1,0,h-1,hh,blo*n+n-1)==blo*n+n-hh){
        dis=blo*n+n-hh;
        int r=find(1,0,h-1,blo*n);
        to=r;
        dis+=r-blo*n;
    }else{
        //puts("Case 2");
        int r=find(1,0,h-1,hh);
        to=r;
        dis=r-hh;
    }
    ha[id]=to;
    add(1,0,h-1,to,1);
    return dis;
}
int main(){
    int m,q,i,j;
    scanf("%d%d%d",&h,&m,&q);
    r=gcd(h,m);
    n=h/r;
    int c=0;
    for(i=0;i<r;i++){
        int np=i;
        for(j=0;j<n;j++){
            pts[np]=c;
            c++;
            np=(np+m)%h;
        }
    }
    long long ans=0;
    while(q--){
        char tmp[3];
        int id;
        scanf("%s%d",tmp,&id);
        if(tmp[0]=='+'){
            int hh;
            scanf("%d",&hh);
            hh=pts[hh];
            int r=solve(hh,id);
            //printf("r=%d\n",r);
            ans+=r;
        }else{
            add(1,0,h-1,ha[id],-1);
        }
    }
    printf("%I64d\n",ans);
}