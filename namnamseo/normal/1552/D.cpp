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

int n;
int a[maxn];

bool dfs(int p, int sm, bool u) {
	if (p == n) return u && !sm;
	return dfs(p+1, sm, u) || dfs(p+1, sm+a[p], 1) || dfs(p+1, sm-a[p], 1);
}

void Work() {
	cin >> n;
	rep(i, n) cin >> a[i];

	if (dfs(0, 0, 0)) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}