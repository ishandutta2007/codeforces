#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

string rev(string s)
{
	string t = "";
	for (int i(s.size() - 1); i >= 0; --i)
		t += s[i];
	return t;
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<bool> is_palin(n);
	vector<string> words(n);
	vector<string> rev_words(n);
	int ans(0);
	vector<bool> used(n);
	vector<string> anss;
	for (auto &e : words)
		cin >> e;
	for (int i(0); i < n; ++i)
		rev_words[i] = rev(words[i]);

	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < i; ++j)
			if (rev_words[j] == words[i] and !used[j])
			{
				used[i] = used[j] = true;
				ans += 2;
				anss.push_back(words[i]);
				break;
			}
	}
	
	bool odd(false);
	string o;
	for (int i(0); i < n; ++i)
		if (!used[i] and rev_words[i] == words[i])
			odd = true, o = words[i];

	if (odd == false)
	{
		cout << ans * m << endl;
		for (auto e : anss)
			cout << e;
		for (int i(anss.size()-1); i >= 0; --i)
			cout << rev(anss[i]);
		cout << endl;
	}
	else
	{
		cout << ans * m + m << endl;
		for (auto e : anss)
			cout << e;
		cout << o;
		for (int i(anss.size() -1); i >=0;--i)
			cout << rev(anss[i]);
		cout<<endl;
	}
}