#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=1e9+7;
const int N=1e6+50;
ll f[21];
ll g[20*N];
int vis[N];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,20) {
		f[i]=f[i-1];
		FOR(j,1,m) if(!g[i*j]) g[i*j]=1,++f[i];
	}
	ll res=1;
	FOR(i,2,n) {
		if(vis[i]) continue;
		int c=1,j=i;
		while(1ll*j*i<=n) {
			j*=i;
			++c;
			vis[j]=1;
		}
		res+=f[c];
	}
	printf("%lld\n",res);
	return 0;
}