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

void solve() {
	int n,B,x,y;
	scanf("%d%d%d%d",&n,&B,&x,&y);
	ll r=0;
	int a=0;
	FOR(i,1,n) {
		if(a+x>B) a=a-y;
		else a=a+x;
		r+=a;
	}
	printf("%lld\n",r);
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}