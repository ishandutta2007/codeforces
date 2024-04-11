#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2000;
int dp[MAXN][MAXN];
int nb_nuits, nb_heures, deb, fin;
vector<int> delta;

int solve(int cur_heure, int ind)
{
	if (dp[cur_heure][ind] != -1)
		return dp[cur_heure][ind];
	int fst_time = (cur_heure + delta[ind]-1)%nb_heures;
	int snd_time = (cur_heure + delta[ind])%nb_heures;
	dp[cur_heure][ind] =  solve(fst_time, ind+1) + (fst_time>= deb and fst_time<=fin ? 1 : 0);
	dp[cur_heure][ind] =  max(dp[cur_heure][ind], solve(snd_time, ind+1) + (snd_time>= deb and snd_time<=fin ? 1 : 0));

	return dp[cur_heure][ind];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_nuits >> nb_heures >> deb >> fin;

	delta.resize(nb_nuits);
	for (auto &v : delta)
		cin >> v;
	for (int j = 0; j < nb_heures; ++j)
		for (int i(0); i < nb_nuits; ++i)
			dp[j][i] = -1;
	for (int i = 0; i < nb_heures; ++i)
		dp[i][nb_nuits] = 0;
	cout << solve(0,0) << endl;
}