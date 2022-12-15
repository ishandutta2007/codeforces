#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '

typedef	long long ll;

int solve(int testcase);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	for (int _t(1); _t <= __t; _t++)
		solve(_t);
}

int bit(int p)
{
	return (1<<p);
}
const int MAXD = 2001;
bool can_reach[MAXD][MAXD];
int masks[10];
int panneaux[MAXD];

int get_mask(string s)
{
	int ret(0);
	for (int i(0); i < SZ(s); ++i)
		ret = 2*ret + s[i]-'0';
	return ret;
}

int solve(int testcase)
{
	masks[0] = get_mask("1110111");
	masks[1] = get_mask("0010010");
	masks[2] = get_mask("1011101");
	masks[3] = get_mask("1011011");
	masks[4] = get_mask("0111010");
	masks[5] = get_mask("1101011");
	masks[6] = get_mask("1101111");
	masks[7] = get_mask("1010010");
	masks[8] = get_mask("1111111");
	masks[9] = get_mask("1111011");
	string ret;
	int nb_chiffres, nb_ajouts;
	cin >> nb_chiffres >> nb_ajouts;
	for (int i(0); i < nb_chiffres; ++i)
	{
		string s; cin >> s;
		panneaux[i] = get_mask(s);
	}	
	can_reach[nb_chiffres][0] = true;
	for (int cur_chiffre(nb_chiffres-1); cur_chiffre >= 0; --cur_chiffre)
		for (int restant(MAXD-1); restant >= 0; --restant)
			for (int change_chiffres(0); change_chiffres <= 9; ++change_chiffres)
			{
				if ((masks[change_chiffres]&panneaux[cur_chiffre]) != panneaux[cur_chiffre]) continue;
				int diff = __builtin_popcount(masks[change_chiffres]^panneaux[cur_chiffre]);
				if (diff <= restant)
					can_reach[cur_chiffre][restant] = (can_reach[cur_chiffre][restant] or can_reach[cur_chiffre+1][restant-diff]);
			}
	if (!can_reach[0][nb_ajouts])
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i(0); i < nb_chiffres; ++i)
	{
		for (int chiffre(9); chiffre >= 0; --chiffre)
		{
			if ((masks[chiffre] & panneaux[i]) != panneaux[i]) continue;
			int nb_diffs = __builtin_popcount(masks[chiffre]^panneaux[i]);
			if (nb_diffs <= nb_ajouts and can_reach[i+1][nb_ajouts - nb_diffs])
			{
				nb_ajouts -= nb_diffs;
				ret += (char)(chiffre+'0');
				break;
			}
		}
	}
	cout << ret << endl;
	return testcase;
}