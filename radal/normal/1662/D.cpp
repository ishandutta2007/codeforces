#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 200;

inline string nob(const string &s)
{
	string o;
	for(char ch: s)
		if(ch != 'B')
			o += ch;
	return o;
}

inline string bmin(string s)
{
	while(true)
	{
		int c = -1;
		for(int i = 1; i < (int)(s.size()); i++)
		{
			if(s[i] == s[i-1])
			{
				c = i-1;
				break;
			}
		}
		if(c == -1)
			break;
		s.erase(s.begin()+c);
		s.erase(s.begin()+c);
	}
	return s;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		string s; cin >> s;
		string t; cin >> t;
		int sb = count(s.begin(), s.end(), 'B');
		int tb = count(t.begin(), t.end(), 'B');
		if(sb % 2 != tb % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		s = nob(s);
		t = nob(t);
		s = bmin(s);
		t = bmin(t);
		if(s == t)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}