#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int l[MAXN + 1];
int r[MAXN + 1];
bool good[MAXN + 1];
int who[MAXN + 1];
string s;
string ans;
int n, k;
int t;
bool doubled[MAXN + 1];

void dfs1(int v)
{
	if (l[v])
		dfs1(l[v]);
	who[t++] = v;
	ans += s[v];
	if (r[v])
		dfs1(r[v]);
}

bool solve(int v, int above)
{
	if (!v)
		return false;
	if (good[v])
	{
		if (solve(l[v], above + 1))
		{
			doubled[v] = true;
			above = 0;
			solve(r[v], 0);
			return true;
		}
		else
		{
			if (1 + above <= k)
			{
				k -= 1 + above;
				doubled[v] = true;
				above = 0;
				solve(r[v], 0);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (solve(l[v], above + 1))
		{
			doubled[v] = true;
			above = 0;
			solve(r[v], 0);
			return true;
		}
		else
			return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cin >> s;
	s = "#" + s;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	ans = "#";
	t = 1;
	dfs1(1);
	for (int i = (int) ans.length() - 2; i >= 1; i--)
	{
		//cout << "who " << i << " " << who[i] << endl;
		if (ans[i] != ans[i + 1])
			good[who[i]] = ans[i] < ans[i + 1];
		else
			good[who[i]] = good[who[i + 1]];
	}
	//cout << "good ";
	//for (int i = 1; i <= n; i++)
		//if (good[i])
			//cout << i << " ";
	//cout << endl;
	//cout << ans << endl;
	solve(1, 0);
	for (int i = 1; i <= n; i++)
	{
		int v = who[i];
		cout << s[v];
		if (doubled[v])
			cout << s[v];
	}
	cout << "\n";
	return 0;
}