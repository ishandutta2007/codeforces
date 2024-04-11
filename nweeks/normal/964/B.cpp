#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, A, B, C, T;
	cin >> N >> A >> B >> C >> T;

	int ans(0);

	for (int i(0); i < N; ++i)
	{
		int t; cin >> t;
		int best(0);
		for (int j(t); j <= T; ++j)
			best = max(best, A - B * (j-t) + (j-t) * C);
		ans += best;
	}
	cout << ans << endl;
}