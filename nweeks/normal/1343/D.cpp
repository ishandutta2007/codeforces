#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '

typedef	long long ll;

int solve(int testcase);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	for (int _t(1); _t <= __t; _t++)
		solve(_t);
}

int solve(int testcase)
{
	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	FOR(i,0,n) cin >> a[i];

	int ans = n;
	vector<int> cnt(2*k+1);
	for (int i(0); i < n/2; ++i)
		cnt[a[i]+a[n-1-i]]++;
	vector<int> pref(2*k+2);
	for (int i(0); i < n/2; ++i)
	{
		pref[1+min(a[i], a[n-1-i])]--;
		pref[k+max(a[i], a[n-1-i])+1]++;
	}
	FOR(i, 1, 2*k+1)
		pref[i]+=pref[i-1];
	FOR(i, 2, 2*k+1)
		ans = min(n + pref[i] -cnt[i], ans);
	pnl(ans);
	return testcase;
}