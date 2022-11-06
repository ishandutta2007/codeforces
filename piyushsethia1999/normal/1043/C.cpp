#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s;
	cin >> s;
	std::vector<string> mins(s.size());
	std::vector<string> maxs(s.size());
	std::vector<std::vector<int> > maxpos(s.size(), std::vector<int> (s.size()));
	std::vector<std::vector<int> > minpos(s.size(), std::vector<int> (s.size()));
	string sp = "a";
	sp[0] = s[0];
	minpos[0][0] = 0;
	maxpos[0][0] = 0;
	mins[0] = sp;
	maxs[0] = sp;

	int n = s.size();

	for (int i = 1; i < s.size(); ++i)
	{
		sp[0] = s[i];
		string maxmax = maxs[i - 1];
		string minmin = mins[i - 1];
		reverse(minmin.begin(), minmin.end());
		reverse(maxmax.begin(), maxmax.end());

		if ((mins[i - 1] + sp) <= (sp + maxmax))
		{
			mins[i] = mins[i - 1] + sp;
			for (int j = 0; j < i; ++j)
			{
				minpos[i][j] = minpos[i - 1][j];
			}
			minpos[i][i] = 0;
		}
		else {
			mins[i] = sp + maxmax;
			for (int j = 0; j < i; ++j)
			{
				minpos[i][j] = maxpos[i - 1][j];
			}
			minpos[i][i] = 1;
		}

		if ((maxs[i - 1] + sp) >= (sp + minmin))
		{
			maxs[i] = maxs[i - 1] + sp;
			for (int j = 0; j < i; ++j)
			{
				maxpos[i][j] = maxpos[i - 1][j];
			}
			maxpos[i][i] = 0;
		}
		else {
			maxs[i] = sp + minmin;
			for (int j = 0; j < i; ++j)
			{
				maxpos[i][j] = minpos[i - 1][j];
			}
			maxpos[i][i] = 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << minpos[n - 1][i] << " ";
	}
}