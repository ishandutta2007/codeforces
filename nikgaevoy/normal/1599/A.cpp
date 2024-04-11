#include <bits/stdc++.h>
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = long long;
using ull = unsigned long long;
//[l,r)

char rev(char c)
{
	if (c == 'L')
		return 'R';
	if (c == 'R')
		return 'L';
}
void zap(string& s, vector<int>& v, int l, int r, int len, vector<pair<int, char>>& rev_ans)
{
	//cout << l << ' ' << r << ' '<<len<<endl;
	if (len % 2 == 1)
	{
		rev_ans.push_back({ v[r - 1], s[len - 1] });
		zap(s, v, l, r - 1, len - 1, rev_ans);
	}
	else if (len ==2)
	{
		if (s[0] == s[1])
		{
			//cout << "HERE " << s[1] << ' ' << rev(s[1]) << endl;
			rev_ans.push_back({ v[l], rev(s[1]) });
			rev_ans.push_back({ v[l+1], s[1] });
		}
		else
		{
			rev_ans.push_back({ v[l + 1], s[1] });
			rev_ans.push_back({ v[l], s[0] });
		}
	}
	else if(len>2)
	{
		if (s[len - 1] == s[len - 2] && s[len - 2] == s[len - 3])
		{
			rev_ans.push_back({ v[r-2], rev(s[len-1]) });
			rev_ans.push_back({ v[r-1], s[len-1] });
			zap(s, v, l, r - 2, len - 2, rev_ans);
		}
		//RLL
		else if (s[len - 1] == s[len - 2] && s[len - 2] != s[len - 3])
		{
			rev_ans.push_back({ v[l], rev(s[len - 2]) });
			rev_ans.push_back({ v[r - 1],s[len-2] });
			zap(s, v, l+1, r - 1, len - 2, rev_ans);
		}
		//RRL
		else if (s[len - 1] != s[len - 2] && s[len - 2] == s[len - 3])
		{
			rev_ans.push_back({ v[r - 1], s[len - 1]});
			rev_ans.push_back({ v[l], s[len - 2] });
			zap(s, v, l+1, r - 1, len - 2, rev_ans);
		}
		else if (s[len - 1] != s[len - 2] && s[len - 2] != s[len - 3])
		{
			rev_ans.push_back({ v[r-1], s[len - 1] });
			rev_ans.push_back({ v[r - 2], s[len - 2] });
			zap(s, v, l, r - 2, len - 2, rev_ans);
		}
	}
}

void solve(istream& cin = std::cin, ostream& cout = std::cout)
{
	int n=10;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i+1;
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	string s;
	cin >> s;
	vector<pair<int, char>>rev_ans;
	zap(s, v, 0, n, n, rev_ans);
	reverse(rev_ans.begin(), rev_ans.end());
	long long ls = 0, rs = 0;
	for (int i = 0; i < n; i++)
	{
		cout << rev_ans[i].first << ' ' << rev_ans[i].second << endl;
		if (rev_ans[i].second == 'L')
			ls += rev_ans[i].first;
		if (rev_ans[i].second == 'R')
			rs += rev_ans[i].first;
		if (s[i] == 'L' && ls <= rs)
			cout << "?! ";
		if (s[i] == 'R' && ls >= rs)
			cout << "?!  ";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int)str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}