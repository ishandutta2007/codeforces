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
int b[N];
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	int m=0;
	FOR(i,1,n) {
		if(m && b[m]>a[i]) {
			int w=b[m];
			--m;
			while(m && b[m]>a[i]) --m;
			b[++m]=w;
		} else b[++m]=a[i];
		
	}
	printf("%d\n",m);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}