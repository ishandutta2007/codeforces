#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn][maxn],b[maxn][maxn];
bool vis[maxn][maxn];
inline int add(int x,int y){return x+y<mod?x+y:x+y-mod;}
inline int sub(int x,int y){return x<y?x-y+mod:x-y;}
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) ans=mul(ans,a);
	return ans;
}
int calc(int x){
	FOR(i,1,n) FOR(j,1,n) a[i][j]=0;
	FOR(i,1,n) FOR(j,i+1,n){
		if(i==j) continue;
		int w=vis[i][j]?x:1;
		a[i][i]=add(a[i][i],w);
		a[j][j]=add(a[j][j],w);
		a[i][j]=sub(a[i][j],w);
		a[j][i]=sub(a[j][i],w);
	}
	int val=1;
	FOR(i,1,n-1){
		FOR(j,i+1,n-1) while(a[j][i]){
			int d=a[i][i]/a[j][i];
			FOR(k,i,n-1) a[i][k]=sub(a[i][k],mul(d,a[j][k]));
			swap(a[i],a[j]);
			val=mod-val;
		}
		val=mul(val,a[i][i]);
	}
	return val;
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		vis[u][v]=vis[v][u]=true;
	}
	FOR(i,1,n){
		b[i][1]=1;
		FOR(j,2,n) b[i][j]=mul(b[i][j-1],i);
		b[i][n+1]=calc(i);
	}
	FOR(i,1,n){
		int d=qpow(b[i][i],mod-2);
		FOR(j,i,n+1) b[i][j]=mul(b[i][j],d);
		FOR(j,1,n){
			if(i==j) continue;
			int d=b[j][i];
			FOR(k,i,n+1) b[j][k]=sub(b[j][k],mul(b[i][k],d));
		}
	}
	FOR(i,1,n) printf("%d ",b[i][n+1]);
}