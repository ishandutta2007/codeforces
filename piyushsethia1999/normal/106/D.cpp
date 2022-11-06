#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>
class ST
{
	std::vector<std::vector<T> > table;
	T (*Union)(T, T b);
public:
	ST(std::vector<T>& a,T (*u)(T, T));
	T query(int l ,int r);
};
template<typename T>
ST<T>::ST(std::vector<T>& a, T (*u)(T, T)) {
	Union = u;
	int n = a.size();
	int k = log2(n);
	table.resize(n, std::vector<T> (k+1));
	for (int i = 0; i < n; ++i)
		table[i][0] = a[i];
	for (int j = 1; j <= k; ++j)
		for (int i = 0; i < (n+1-(1<<j)); ++i)
			table[i][j] = Union(table[i][j-1], table[i+(1<<(j-1))][j-1]);
}
template<typename T>
T ST<T>::query(int l, int r)
{
	int m = log2(r-l+1);
	return this->Union(table[l][m], table[r - (1 << m) + 1][m]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m;
	std::vector<string> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	std::vector<int> loc(26, -1);
	std::vector<std::vector<char> > grid1(n, std::vector<char> (m, false));
	std::vector<std::vector<char> > grid2(m, std::vector<char> (n, false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(s[i][j] <= 'Z' && s[i][j] >= 'A')
			{
				loc[s[i][j] - 'A'] = i*m+j;
				grid2[j][i] = 1;
				grid1[i][j] = 1;
			}
			else if(s[i][j] != '#')
			{
				grid1[i][j] = 1;
				grid2[j][i] = 1;
			}
		}
	}
	int K;
	cin >> K;
	std::vector<char> dir(K);
	std::vector<int> len(K);
	for (int i = 0; i < K; ++i)
	{
		cin >> dir[i];
		cin >> len[i];
	}
	std::vector<ST<char>> row;
	std::vector<ST<char>> column;
	auto f = [](char a, char b) -> char{return (a&b);};
	for (int i = 0; i < n; ++i)
		row.pb(ST<char>(grid1[i], f));
	for (int i = 0; i < m; ++i)
		column.pb(ST<char>(grid2[i], f));
	string s1 = "";
	for (int k = 0; k < 26; ++k)
	{
		if(loc[k] != -1)
		{
			int i = loc[k]/m;
			int j = loc[k]%m;
			bool res = true;
			for (int in = 0; in < K && res; ++in)
			{
				if(k == 1)
					print(in);
				if(dir[in] == 'N')
				{
					if(i - len[in] < 0 || (!column[j].query(i - len[in], i)))
						res = false;
					else
						i -= len[in];
				}	
				else if(dir[in] == 'S')
				{
					if(i + len[in] >= n || (!column[j].query(i, len[in] + i)))
						res = false;
					else
						i += len[in];
				}
				else if(dir[in] == 'W')
				{
					if(j - len[in] < 0 || (!row[i].query(j - len[in], j)))
						res = false;
					else
						j -= len[in];
				}
				else 
				{
					if(j + len[in] >= m || (!row[i].query(j, len[in] + j)))
						res = false;
					else
						j += len[in];
				}
			}
			if(res)
				s1 += (char)('A' + k);
		}
	}
	if(s1 != "")
		cout << s1;
	else
		cout << "no solution";
}