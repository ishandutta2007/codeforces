#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
long long pref[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n >> s;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			pref[i] = pref[i - 1] + a[i];
		}
		multiset<long long> st;
		int len = 0;
		int ans = -1;
		int ptr = 0;
		for (int i = 1; i <= n; i++)
		{
			//cout << "iter " << i << endl;
			if (!st.size() || (*st.begin()) - pref[i - 1] + s >= 0)
			{
				while (ptr + 1 <= n && pref[ptr + 1] - pref[i - 1] + s >= 0)
				{
					ptr++;
					st.insert(pref[ptr]);
				}
				if ((int) st.size() > len)
				{
					len = (int) st.size();
					ans = i;
				}
			}
			if (st.size())
				st.erase(st.find(pref[i]));
			ptr = max(ptr, i);
		}
		if (len)
		{
			cout << ans << " " << ans + len - 1 << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
	return 0;
}