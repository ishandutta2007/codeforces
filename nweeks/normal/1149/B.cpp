#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 1e5+1;
const int MAXLEN = 251;
const int SIG = 26;
string s;
int longueur, nb_requetes;
int nxt[MAXN][SIG];
int dp[MAXLEN][MAXLEN][MAXLEN];


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> longueur >> nb_requetes;
	cin >> s;
	
	for (int i(longueur-1); i >= 0; --i)
		for (int c(0); c < SIG; ++c)
		{
			if (c == s[i]-'a')
				nxt[i][c] = i;
			else
				nxt[i][c] = (i == longueur-1 ? longueur : nxt[i+1][c]);
		}
	for (int i(0); i < MAXLEN; ++i)
		for (int j(0); j < MAXLEN; ++j)
			for (int k(0); k < MAXLEN; ++k)
				dp[i][j][j] = longueur+1;
	dp[0][0][0] = 0;


	array<vector<char>, 3> words;
	for (int i(0); i < 3; ++i)
		words[i] = {};
	while (nb_requetes--)
	{
		char op;
		int id;
		cin >> op >> id;
		--id;
		if (op == '-')
		{
			pair<int,int> ranges[3] = {{0, SZ(words[0])}, {0, SZ(words[1])}, {0, SZ(words[2])}};
			ranges[id] = {SZ(words[id]), SZ(words[id])};
			for (int i(ranges[0].first); i <= ranges[0].second; ++i)
				for (int j(ranges[1].first); j <= ranges[1].second; ++j)
					for (int k(ranges[2].first); k <= ranges[2].second; ++k)
						dp[i][j][k] = longueur+1;
			words[id].pop_back();
		}
		else
		{
			char c;
			cin >> c;
			c -= 'a';
			pair<int,int> ranges[3] = {{0, SZ(words[0])}, {0, SZ(words[1])}, {0, SZ(words[2])}};
			words[id].push_back(c);
			ranges[id] = {SZ(words[id]), SZ(words[id])};
			for (int i(ranges[0].first); i <= ranges[0].second; ++i)
				for (int j(ranges[1].first); j <= ranges[1].second; ++j)
					for (int k(ranges[2].first); k <= ranges[2].second; ++k)
					{
						dp[i][j][k] = longueur+1;
						if (i and dp[i-1][j][k] < longueur)
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][words[0][i-1]] + 1);
						if (j and dp[i][j-1][k] < longueur)
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][words[1][j-1]] + 1);
						if (k and dp[i][j][k-1] < longueur)
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][words[2][k-1]] + 1);
					}
		}
		if (dp[SZ(words[0])][SZ(words[1])][SZ(words[2])] <= longueur)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}