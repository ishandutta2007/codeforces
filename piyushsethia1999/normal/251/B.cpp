#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

std::vector<std::vector<int> > grid;
int n, k;

void Inv(std::vector<int>& v, std::vector<int>& iv)
{
	for (int i = 0; i < v.size(); ++i)
		iv[v[i]] = i;
}

void applyperm(std::vector<int>& v, int i, int j)
{
	for (int o = 0; o < v.size(); ++o)
		grid[j][o] = grid[i][v[o]];
}

bool check(std::vector<int>& v1, std::vector<int>& v2)
{
	for (int i = 0; i < v1.size(); ++i)
		if(v1[i] != v2[i])
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> n >> k;
	grid.resize(2*k+1, std::vector<int> (n));
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
	}
	std::vector<int> inp(n);
	Inv(p, inp);
	std::vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		s[i]--;
		grid[k][i] = i;
	}
	for (int i = 0; i < k; ++i) {
		applyperm(p, k + i, k + i + 1);
		applyperm(inp, k - i, k - i - 1);
	}
	int r = k+1;
	int l = k+1;
	for (int i = 0; i <= k; ++i) {
		if(check(s, grid[k+i]))
			r = min(r, i);
		if(check(s, grid[k-i]))
			l = min(l, i);
	}
	print(l, r);
	print(p);
	print(inp);
	print(s);
	print(grid);
	if((l > k && r > k) || (l == 0) || (l == 1 && r == 1 && k > 1))
		cout << "NO";
	else if((l % 2 == k % 2) || (r % 2 == k % 2))
		cout << "YES";
	else
		cout << "NO";
}