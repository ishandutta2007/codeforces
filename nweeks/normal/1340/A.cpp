#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << (solve() ? "Yes" : "No") << '\n';
}

ll solve(void)
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &v : p)
    {
    	cin >> v;
    	--v;
    }
    vector<bool> picked(n);
    int l(0);
    while (l < n)
    {
    	int cnt = 0;
    	while (p[l]+cnt < n and !picked[p[l]+cnt])
    		++cnt;
    	for (int i(0); i < cnt; ++i)
    		if (l+i >= n or p[l+i] != p[l]+i)
    			return false;
    	for (int i(0); i < cnt; ++i)
    		picked[p[l]+i] = true;
    	l += cnt;
    }

	return 1;
}