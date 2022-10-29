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
map<int,int> b;
void solve() {
	int n,K;
	scanf("%d%d",&n,&K);
	FOR(i,1,n) scanf("%d",&a[i]);
	int r=0;
	if(n==1) {
		if(a[n]==K) r=1;
	}
	sort(a+1,a+n+1);
	b.clear();
	b[a[1]]=1;
	FOR(i,2,n) {
		if(b[a[i]-K]) {
			r=1;
		}
		b[a[i]]=1;
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