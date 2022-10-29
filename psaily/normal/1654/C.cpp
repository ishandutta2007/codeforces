#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=1e6+50;
map<ll,int> cnt;
map<ll,int> vis;
int a[N];
ll b[N];
void solve() {
	cnt.clear();
	vis.clear();
	int n;
	scanf("%d",&n);
	ll t=0;
	FOR(i,1,n) scanf("%d",&a[i]),t+=a[i];
	
	int m=0;
	ll v=t;
	while(true) {
		b[++m]=v;
		v=v/2;
		if(!v) break;
	}
	v=t;
	while(true) {
		b[++m]=v;
		if(v==1) break;
		v=(v+1)/2;
	}
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	FOR(i,1,m) vis[b[i]]=1;
	
	int res=1;
	FOR(i,1,n) {
		if(!vis[a[i]]) res=0;
		cnt[a[i]]--;
	}
	cnt[b[m]]++;
	DOR(i,m,1) {
		if(cnt[b[i]]<0) res=0;
		else cnt[b[i]/2]+=cnt[b[i]],cnt[(b[i]+1)/2]+=cnt[b[i]];
	}
	
	puts(res?"YES":"NO");
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}