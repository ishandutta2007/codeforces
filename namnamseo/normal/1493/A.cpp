#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;

int n, k;

int main()
{
	cppio();

	int tc; cin >> tc;
rep(tci, tc) {
	cin >> n >> k;
	vector<int> ans;
	for (int i=(k+1)/2; i<k; ++i) ans.pb(i);
	for (int i=k+1; i<=n; ++i) ans.pb(i);
	cout << ans.size() << '\n';
	int as = sz(ans);
	rep(i, as) {
		cout << ans[i] << " \n"[i==as-1];
	}
}



	return 0;
}