#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

void p(int x, int y)
{
	cout << x << " " << y << "\n";
}

void Print(int i, int j, int r)
{
	p(i, j);
	p(i-r, j);
	p(i+r, j);
	p(i, j-r);
	p(i, j+r);
	exit(0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	string s[n];
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	k--;
	print(k);
	for (int r = 1; r <= (min(n, m)/2); ++r)
		for (int i = r; i < n-r; ++i)
			for (int j = r; j < m-r; ++j)
				if(s[i][j] == '*' && s[i-r][j] == '*' && s[i+r][j] == '*' && s[i][j-r] == '*' && s[i][j+r] == '*')
					if(!(k--))
						Print(i + 1, j + 1, r);
	print(k);
	cout << -1;
}