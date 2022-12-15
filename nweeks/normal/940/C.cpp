#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;

bool	in[26] = {};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;

	std::string s; std::cin >> s;
	
	for (auto c : s)
		in[c-'a'] = true;
	
	char biggest;
	char smallest;
	for (int i(25); i >= 0; --i)
		if (in[i])
		{
			biggest = i+'a';
			break;
		}
	for (int i(0); i < 26; ++i)
		if (in[i])
		{
			smallest = i+'a';
			break ;
		}

	std::string t;
	t.resize(k);
	if (k <= n)
	{
		int	right = k-1;
		while (s[right] == biggest)
			right--;
		char c = s[right];
		for (int i(c-'a'+1); ; ++i)
			if (in[i])
			{
				t[right] = i+'a';
				break ;
			}
		for (int i(0); i < right; ++i)
			t[i] = s[i];
		for (int i(right + 1); i < k; ++i)
			t[i] = smallest;
	}
	if (k > n)
	{
		for (int i(0); i < n; ++i)
			t[i] = s[i];
		for (int i(n); i < k; ++i)
			t[i] = smallest;
	}
	pnl(t);
}