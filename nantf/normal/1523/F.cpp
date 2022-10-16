#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353,INF=1e9;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
struct wtf{
	int x,y,t;
	bool operator<(const wtf &w)const{return t<w.t;}
}w[maxn];
int n,m,xa[maxn],ya[maxn],xb[maxn],yb[maxn],t[maxn],ans;
int f[16666][111],g[16666][111],p[16666][22],q[16666][111];
inline int dis(int xl,int yl,int xr,int yr){
	return abs(xl-xr)+abs(yl-yr);
}
inline void chkmax(int &x,int y){x=max(x,y);}
inline void chkmin(int &x,int y){x=min(x,y);}
int main(){
	n=read();m=read();
	FOR(i,1,n) xa[i]=read(),ya[i]=read();
	FOR(i,1,m){
		int x=read(),y=read(),t=read();
		w[i]=(wtf){x,y,t};
	}
	sort(w+1,w+m+1);
	FOR(i,1,m) xb[i]=w[i].x,yb[i]=w[i].y,t[i]=w[i].t;
	FOR(i,0,(1<<n)-1) FOR(j,0,m) f[i][j]=INF,g[i][j]=-INF;
	FOR(i,1,n) f[1<<(i-1)][0]=0;
	FOR(i,1,m) g[0][i]=1;
	FOR(i,0,(1<<n)-1){
		FOR(j,1,n) if(!((i>>(j-1))&1)){
			p[i][j]=INF;
			FOR(k,1,n) if((i>>(k-1))&1) chkmin(p[i][j],dis(xa[j],ya[j],xa[k],ya[k]));
		}
		FOR(j,1,m){
			q[i][j]=INF;
			FOR(k,1,n) if((i>>(k-1))&1) chkmin(q[i][j],dis(xb[j],yb[j],xa[k],ya[k]));
		}
	}
	FOR(i,0,(1<<n)-1){
		FOR(j,0,m) if(f[i][j]!=INF){
			FOR(k,1,n) if(!((i>>(k-1))&1)) chkmin(f[i|(1<<(k-1))][j],f[i][j]+p[i][k]);
			FOR(k,1,m) if(f[i][j]+q[i][k]<=t[k]) chkmax(g[i][k],j+1);
		}
		FOR(j,1,m) if(g[i][j]!=-INF){
			ans=max(ans,g[i][j]);
			FOR(k,1,n) if(!((i>>(k-1))&1))
				chkmin(f[i|(1<<(k-1))][g[i][j]],t[j]+min(dis(xb[j],yb[j],xa[k],ya[k]),p[i][k]));
			FOR(k,j+1,m) if(t[j]+min(dis(xb[j],yb[j],xb[k],yb[k]),q[i][k])<=t[k])
				chkmax(g[i][k],g[i][j]+1);
		}
	}
	printf("%d\n",ans);
}