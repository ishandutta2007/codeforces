#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=3e5+50;
const int Mod=1e9+7;
int a[N];
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	int p=1;
	while(p<=n && a[p]==p) ++p;
	if(p<=n) {
		int q;
		FOR(i,p,n) if(p==a[i]) q=i;
		FOR(i,p,(p+q)/2) {
			swap(a[i],a[p+q-i]);
		}
	}
	FOR(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}