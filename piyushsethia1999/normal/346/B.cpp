#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

string func(string s1, string s2, string virus)
{
	int n = s1.size();
	int m = s2.size();
	int v = virus.size();

	std::vector<int> lpsv(v, 0);
	for (int i = 1; i < v; ++i)
	{
		lpsv[i] = lpsv[i-1];
		while(lpsv[i] > 0 && virus[lpsv[i]] != virus[i])
			lpsv[i] = lpsv[lpsv[i]-1];
		if(virus[lpsv[i]] == virus[i]) lpsv[i]++;
	}
	std::vector<std::vector<int> > lcs(n+1, std::vector<int>(m+1, 0));
	std::vector<std::vector<int> > lps(n+1, std::vector<int> (m+1, 0));
	std::vector<std::vector<string> > str(n+1, std::vector<string> (m+1, ""));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if(s1[i-1] == s2[j-1])
			{
				if(lps[i-1][j-1] == v-1 && virus[v-1] == s1[i-1]) {
					lps[i][j] = v-1;
					lcs[i][j] = lcs[i-1][j-1];
					str[i][j] = str[i-1][j-1];
				}
				else
				{
					int tlps = lps[i-1][j-1];
					while(tlps > 0 && virus[tlps] != s1[i-1])
						tlps = lpsv[tlps-1];
					if(virus[tlps] == s1[i-1]) tlps++;
					lps[i][j] = tlps;
					lcs[i][j] = lcs[i-1][j-1] + 1;
					str[i][j] = str[i-1][j-1] + s1[i-1];
				}
			}
			else 
			{
				if(lcs[i-1][j] > lcs[i][j-1])
				{
					lcs[i][j] = lcs[i-1][j];
					lps[i][j] = lps[i-1][j];
					str[i][j] = str[i-1][j];
				}
				else if(lcs[i][j-1] > lcs[i-1][j])
				{
					lcs[i][j] = lcs[i][j-1];
					lps[i][j] = lps[i][j-1];
					str[i][j] = str[i][j-1];
				}
				else
				{
					if(lps[i-1][j] < lps[i][j-1])
					{
						lcs[i][j] = lcs[i-1][j];
						lps[i][j] = lps[i-1][j];
						str[i][j] = str[i-1][j];
					}
					else
					{
						lcs[i][j] = lcs[i][j-1];
						lps[i][j] = lps[i][j-1];
						str[i][j] = str[i][j-1];
					}
				}
			}
		}
	}
	return str[n][m];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	string s1, s2, virus;
	cin >> s1 >> s2 >> virus;
	string ss = func(s1, s2, virus);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(virus.begin(), virus.end());
	string sr = func(s1, s2, virus);
	int n1 = ss.size();
	int n2 = sr.size();
	reverse(sr.begin(), sr.end());
	if(n1 > n2)
	{
		cout << ss;
	}
	else if(n2 > n1)
	{
		cout << sr;
	}
	else if(n1 != 0)
	{
		cout << ss;

	}
	else {

		cout << 0;
	}
}