#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	string s; cin >> s;
	string t; cin >> t;
	std::vector<std::vector<int> > a(26);
	for (int i = 0; i < n; ++i)
	{
		a[t[i] - 'a'].pb(i);
	}
	std::vector<int> siz(26);
	for (int i = 0; i < 26; ++i)
	{
		siz[i] = a[i].size();
	}
	std::vector<int> in(26, 0);
	std::vector<int> vec(n, 0);
	bool can = false;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if(in[s[i] - 'a'] == siz[s[i] - 'a'])
		{
			can = true;
			break;
		}
		vec[i] = a[s[i] - 'a'][in[s[i] - 'a']++];
	}
	if(can) {
		cout << -1;
		exit(0);
	}
	print(vec);
	print(a);
	std::vector<int> res;
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(vec[j] > vec[j+1])
			{
				vec[j] ^= vec[j+1];
				vec[j+1] ^= vec[j];
				vec[j] ^= vec[j+1];
				cnt++;
				res.pb(j+1);
			}
		}
	}
	print(vec);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; ++i)
		cout << res[i] << " ";
}