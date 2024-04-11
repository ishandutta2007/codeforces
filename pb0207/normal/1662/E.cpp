#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef long long ll;
const int N=2e5+50;
int sum[N];
int n;
void upd(int x) {
	for(; x<=n; x+=x&-x) ++sum[x];
}
int qry(int x) {
	int t=0;
	for(; x; x^=x&-x) t+=sum[x];
	return t;
}
int qry(int l,int r) {
	return qry(r)-qry(l-1);
}
int a[N],b[N];
void solve() {
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]),b[a[i]]=i;
	ll res=0;
	FOR(i,1,n) sum[i]=0;
	DOR(i,n,1) {
		if(i<n) {
			ll t=0;
			if(b[i+1]<b[i]) t=qry(b[i],n)+qry(1,b[i+1]-1);
			else t=qry(b[i],b[i+1]-1);
			res+=i*t;
		}
		upd(b[i]);
	}
	printf("%lld\n",res);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}