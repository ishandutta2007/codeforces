#define FNAME "test"

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n - 1); i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)
#define forba(i, b, a) for (int i = b - 1; i >= a; i--)

#ifndef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int n, len, ind, b[30][30], used[105];
string s[105];
vector <int> temp;

void dfs (int v)
{
 	used[v] = 1;
 	for (int j = 0; j < 26; j++)
 		if (used[j] == 0 && b[v][j])
 			dfs(j);
 	temp.pb(v);
}

int main()
{
#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 1; i < n; i++)
	{
		len = min(s[i - 1].length(), s[i].length());
		int ind = -1;
		for (int j = 0; j < len; j++)
			if (s[i][j] != s[i - 1][j])
			{
				ind = j;
				break;
			}
		if (ind == -1 && s[i - 1].length() > s[i].length())
		{
			puts("Impossible");
			return 0;
		}
		if (ind != -1)
			b[s[i - 1][ind] - 'a'][s[i][ind] - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++)
		if (used[i] == 0)
			dfs(i);
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < (int) temp.size(); i++)
		for (int j = 0; j <= i; j++)
			if (b[temp[i]][temp[j]])
			{
				puts("Impossible");
				return 0;
        	}
    for (int i = 0; i < (int) temp.size(); i++)
    	printf("%c", 'a' + temp[i]);
    return 0;
}