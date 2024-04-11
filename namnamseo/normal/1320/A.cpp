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

int n;
const int maxn = 2e5+10;
int b[maxn];

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> b[i];

	map<int,vector<int>> t;
	rrep(i, n) { t[i-b[i]].pb(i); }

	ll ans = 0;

	for(auto& tmp:t) {
		auto &v = tmp.y;
		ll s = 0;
		for(int x:v) s += b[x];
		ans = max(ans, s);
	}

	cout << ans << endl;
	return 0;
}