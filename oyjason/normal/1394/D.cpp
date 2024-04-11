#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 1100010
#define INF 4000000000000ll
int n,m,fs[M],nt[M<<1],to[M<<1],tmp;
int h[M],d[M]; LL Fu[M],Fd[M],v[M],ans,t[M];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline void DP(int x,int last){
    for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last) DP(to[i],x);
    LL now=0; m=0;
    for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last)
        now+=Fd[to[i]],t[++m]=Fu[to[i]]-Fd[to[i]];
    sort(t+1,t+m+1);
    for(int out=m,in=0,i=0;i<=m;i++,out--,in++){
        if(!last) ans=min(ans,now+(LL)max(out,in)*v[x]); 
        else{
            if(h[x]<=h[last]) Fu[x]=min(Fu[x],now+(LL)max(out+1,in)*v[x]);
            if(h[x]>=h[last]) Fd[x]=min(Fd[x],now+(LL)max(out,in+1)*v[x]);
        } now+=t[i+1];
    }
}
int main(){
    n=read(),memset(fs,-1,sizeof(fs));
    for(int x=1;x<=n;x++) Fd[x]=Fu[x]=INF;
    for(int x=1;x<=n;x++) v[x]=read();
    for(int x=1;x<=n;x++) h[x]=read();
    for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x);
    ans=INF,DP(1,0),printf("%lld\n",ans);
	return 0;
}