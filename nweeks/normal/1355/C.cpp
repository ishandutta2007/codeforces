#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll A, B, C, D;
	cin >> A >> B >> C >> D;

	ll ans(0);
	for (ll sum(C+1); sum <= B + C; ++sum)
	{
		ll lft = max(A, sum - C);
		ll rgt = min(B, sum - B);
		if (lft > rgt) continue;
		ans += (rgt-lft+1) * (min(D, sum-1)-C+1);
	}
	cout << ans << endl;
}