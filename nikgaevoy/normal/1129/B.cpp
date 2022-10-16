#include <bits/stdc++.h>

using namespace std;

using ll = long long;


long long find_answer(const vector<int> &a)
{
	int n = a.size();
	long long res = 0;
	long long cur = 0;
	int k = -1;

	for (int i = 0; i < n; i++)
	{
		cur = cur + a[i];

		if (cur < 0)
		{
			cur = 0;
			k = i;
		}

		res = max(res, (i - k) * cur);
	}

	return res;
}


long long stupid(const vector<int> &a)
{
	ll ans = 0;

	vector<ll> ps(a.size() + 1);

	for (int i = 1; i < ps.size(); i++)
		ps[i] = ps[i - 1] + a[i - 1];

	for (int l = 0; l < a.size(); l++)
		for (int r = l; r <= a.size(); r++)
			ans = max(ans, (r - l) * (ps[r] - ps[l]));

	return ans;
}


bool check(const vector<int> &a, int k)
{
	return *max_element(a.begin(), a.end()) <= int(1e6) && *min_element(a.begin(), a.end()) >= int(-1e6) &&
	       stupid(a) - find_answer(a) == k;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int k;

	cin >> k;

	for (int x = 1; clock() < 0.9 * CLOCKS_PER_SEC; x++)
		for (int l = 2; l < 2000; l++)
			if ((k + x) % l == 0 && (k + x) / l < int(1e6) - x)
			{
				vector<int> ans(l + 1);

				ans[ans.size () - 2] = -x;
				ans.back () = (k + x) / l + x;

				assert(check(ans, k));

				cout << ans.size () << endl;

				for (auto it : ans)
					cout << it << ' ';
				cout << endl;

				return;
			}


	cout << -1 << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}