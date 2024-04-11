#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(void)
{
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int ret(0);
	for (int i(0); i < 4; ++i)
		for (int j(0); j < 4; ++j)
			if (i != j)
				for (int k(0); k < 4; ++k)
					if (k != i and k != j)
						for (int l(0); l < 4; ++l)
							if (l != i and l != j and l != k)
								ret = max(ret, min(a[i], a[j]) * min(a[k], a[l]));
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}