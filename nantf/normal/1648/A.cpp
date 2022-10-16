#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353,INF=1e9;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m;
vector<int> x[maxn],y[maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m){
		int w=read();
		x[w].PB(i);y[w].PB(j);
	}
	ll ans=0;
	FOR(i,1,1e5) if(!x[i].empty()){
		int sz=x[i].size();
		sort(x[i].begin(),x[i].end());
		sort(y[i].begin(),y[i].end());
		FOR(j,0,sz-1) ans+=1ll*x[i][j]*(j-(sz-1-j));
		FOR(j,0,sz-1) ans+=1ll*y[i][j]*(j-(sz-1-j));
	}
	printf("%lld\n",ans);
}