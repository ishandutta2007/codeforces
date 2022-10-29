#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+50;
const int Mod=1e9+7;
map<int,int> vis;
ll res;
int a[N];
ll f[N];
int n,p;
void solve(int x) {
	int _x=x;
	while(x) {
		if(vis[x]) return ;
		if(x%2==0) {
			if(x%4==0) x/=4;
			else break;
		} else {
			x=(x-1)/2;
		}
	}
	x=_x;
	vis[x]=1;
	int e=floor(p-log2(x+0.5));
	if(e>=0) {
		res+=f[e];
		res%=Mod;
//		cerr << x << " " << e << " " << f[e] << endl;
	}
}
int main() {
	f[0]=1;f[1]=1;
	n=2e5;
	FOR(i,2,n) f[i]=(f[i-2]+f[i-1])%Mod;
	FOR(i,1,n) f[i]=(f[i]+f[i-1])%Mod;
	scanf("%d%d",&n,&p);
	FOR(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	FOR(i,1,n) solve(a[i]);
	printf("%lld\n",res);
	return 0;
}