#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
#define fi first
#define se second

const int N=4e5+50;

int a[N];
void solve() {
	int n,K;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	int c0=0,c1=0;
	FOR(i,1,n) {
		if(a[i]==0) c0++;
		if(a[i]==1) c1++;
	}
	int r=0;
	if(c1==0) r=1;
	else if(c0==0) {
		sort(a+1,a+n+1);
		int w=1;
		FOR(i,2,n) {
			if(a[i-1]+1==a[i]) {
				w=0;
			}
		}
		if(w) r=1;
	}
	
	puts(r?"YES":"NO");
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}