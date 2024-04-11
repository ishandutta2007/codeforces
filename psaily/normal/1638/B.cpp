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
int a[N],b[2];
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	b[0]=b[1]=0;
	FOR(i,1,n) {
		if(a[i]<b[a[i]&1]) {
			puts("No");
			return ;
		}
		b[a[i]&1]=a[i];
	}
	puts("Yes");
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}