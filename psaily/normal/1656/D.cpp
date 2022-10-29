#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 

// void print(ll x) {
// 	if (!x) return;
// 	print(x/10);
// 	printf("%d",(int)x%10);	
// }
void solve() {
	ll n;
	cin>>n;
	int t=3;
	while (n%2==0) n/=2,t++;
	// 2^t * n 
	ll k=min(2*n,1ll<<(t-1));
	k/=2;
	if (k<2) puts("-1");
	else printf("%lld\n",k);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	int _;
	for (cin>>_;_;_--) {
		solve();
	}
	return 0;	
}