#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline void qmo(int& x){x+=((x>>31)&mod);}
int n,m,px,py,nx,ny,x[5],y[5],ax[5],ay[5],f[2][41][41][41][41][2][2],cur;
// xs,ys,|x|s,|y|s
inline int& F(int a,int b,int c,int d,int e,int p,int q){return f[a][b-nx][c-ny][d][e][p][q];}
int main(){
	n=read();m=read()*2;
	FOR(i,0,n-1){
		x[i]=read(),y[i]=read();
		ax[i]=abs(x[i]);
		ay[i]=abs(y[i]);
		(x[i]>0?px:nx)+=2*x[i];
		(y[i]>0?py:ny)+=2*y[i];
	}
	F(0,0,0,0,0,0,0)=1;
	FOR(i,0,30) FOR(j,0,n-1){
		cur^=1;
		MEM(f[cur],0);
		FOR(a,nx,px) FOR(b,ny,py) FOR(c,0,px-nx) FOR(d,0,py-ny) FOR(p,0,1) FOR(q,0,1) if(F(cur^1,a,b,c,d,p,q)){
			qmo(F(cur,a,b,c,d,p,q)+=F(cur^1,a,b,c,d,p,q)-mod);
			qmo(F(cur,a+x[j],b+y[j],c+ax[j],d+ay[j],p,q)+=F(cur^1,a,b,c,d,p,q)-mod);
		}
		if(j!=n-1) continue;
		cur^=1;
		MEM(f[cur],0);
		FOR(a,nx,px) FOR(b,ny,py) if(a%2==0 && b%2==0) FOR(c,0,px-nx) FOR(d,0,py-ny) FOR(p,0,1) FOR(q,0,1) if(F(cur^1,a,b,c,d,p,q)){
//			printf("f(%d,%d,%d,%d,%d,%d,%d,%d)=%d\n",i,j,a,b,c,d,p,q,F(cur^1,a,b,c,d,p,q));
			int pp=0,qq=0,t1=c%2,t2=(m>>i)&1;
			if(t1==t2) pp=p;
			else pp=t1>t2;
			t1=d%2;
			if(t1==t2) qq=q;
			else qq=t1>t2;
			qmo(F(cur,a/2,b/2,c/2,d/2,pp,qq)+=F(cur^1,a,b,c,d,p,q)-mod);
		}
	}
	printf("%d\n",(F(cur,0,0,0,0,0,0)-1+mod)%mod);
}