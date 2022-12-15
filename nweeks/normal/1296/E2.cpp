#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> col(n);
	vector<int> prev(n);
	vector<int> biggest(26);
	for (int i(0); i < 26; ++i)
		biggest[i] = 0;
	for (int i(0); i < n; ++i)
	{
		int big(0);
		for (int j(s[i]-'a'+1); j < 26; ++j)
			big = max(big, biggest[j]);
		col[i] = big+1;
		biggest[s[i]-'a'] = big+1;
	}

	int nb_col(1);
	for (int i(0); i < n; ++i)
		nb_col = max(nb_col, col[i]);
	cout << nb_col << endl;
	for (int i(0); i < n; ++i)
		cout << col[i] << " \n"[i == n-1];
	
}