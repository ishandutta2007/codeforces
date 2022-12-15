#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int prev(0);
		int ans(0);
		for (int i(0); i < n; ++i)
		{
			int cur;
			cin >> cur;
			if (cur == prev-1) continue;
			if (cur == prev) ++cur;
			prev = cur;
			++ans;
		}
		cout << ans << endl;
	}
}