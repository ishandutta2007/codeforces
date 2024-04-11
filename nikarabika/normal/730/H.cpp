#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 7;

int n, m;
string s[N];
int a[N];
bool mark[N];

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<m; i++)
	{
		cin >> a[i];
		a[i]--;
		mark[a[i]] = true;
	}
	for (int i=0; i<m; i++)
		for (int j=0; j<i; j++)
			if (s[a[i]].size() != s[a[j]].size())
			{
				cout << "No\n";
				return 0;
			}
	int sz = s[a[0]].size();
	string res;
	res = s[a[0]];
	for (int i=0; i<m; i++)
		for (int j=0; j<sz; j++)
			if (res[j] != '?' && res[j] != s[a[i]][j])
				res[j] = '?';
	for (int i=0; i<n; i++)
		if (!mark[i] && res.size() == s[i].size())
		{
			bool flag = false;
			for (int j=0; j<sz; j++)
				if (res[j] != '?' && s[i][j] != res[j])
					flag = true;
			if (!flag)
			{
				cout << "No\n";
				return 0;
			}
		}
	cout << "Yes\n" << res << "\n";
	return 0;
}