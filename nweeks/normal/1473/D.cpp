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
		int n,m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<pair<int, int>> segStart(n+1);
		vector<pair<int, int>> segEnd(n+1);
		vector<int> val(n+1);
		segStart[0] = make_pair(0, 0);
		int curVal(0);
		for (int i(0); i < n; ++i)
		{
			if (s[i] == '+') curVal++;
			else curVal--;
			val[i+1] = curVal;
			segStart[i+1] = make_pair(min(segStart[i].first, curVal), max(segStart[i].second, curVal));
		}
		curVal = 0;
		segEnd[n] = make_pair(0, 0);
		for (int i(n-1); i >= 0; --i)
		{
			int t(0);
			if (s[i] == '+') t=1;
			else t=-1;
			segEnd[i] = make_pair(
				min(segEnd[i+1].first + t, t), max(segEnd[i+1].second + t, t)
			);
		}
		while (m--)
		{
			int l,r ;
			cin >> l >> r;
			pair lft = segStart[l-1];
			pair rgt = segEnd[r];
			rgt.first += val[l-1];
			rgt.second += val[l-1];
			pair ret = make_pair(min(lft.first, rgt.first), max(lft.second, rgt.second));
			cout << ret.second - ret.first +1 << '\n';
		}
	}
}