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
	cin >> __t;
	for (int _t(1); _t <= __t; _t++)
		solve(_t);
}

vector<vector<int> > which_seg;
vector<vector<int> > seg;
int sz_perm;

bool attempt(int start)
{
	vector<int> nb_actifs(sz_perm-1);
	FOR(i,0, sz_perm)
		FORR(v, which_seg[i])
			nb_actifs[v]++;
	vector<int> pos(sz_perm, -1);
	pos[start]=0;
	vector<int> perm;
	perm.pb(start);
	FOR(i,1,sz_perm)
	{
		bool found(false);
		int cur = perm.back();
		FORR(v, which_seg[cur])
			nb_actifs[v]--;
		FORR(v, which_seg[cur])
			if (nb_actifs[v]==1)
			{
				int nxt(-1);
				FORR(u, seg[v])
				{
					if (pos[u]==-1)
						nxt=u;
					else if (i+1-pos[u] > SZ(seg[v]))
							return false;
				}
				found=true;
				perm.pb(nxt);
				pos[nxt]=i;
			}
		if (!found) return false;
	}
	FORR(v, perm) pns(v+1);
	cout<<'\n';
	return true;
}

int solve(int testcase)
{
	cin >> sz_perm;
	which_seg.clear();
	which_seg.resize(sz_perm);
	seg.clear();
	seg.resize(sz_perm-1);
	for (int i(0); i < sz_perm-1; ++i)
	{
		int nb; cin >> nb;
		seg[i].resize(nb);
		for (int j(0); j < nb; ++j)
		{
			cin >> seg[i][j];
			--seg[i][j];
			which_seg[seg[i][j]].pb(i);
		}
	}
	FOR(start,0, sz_perm)
		if (attempt(start))
			return 0;
	return testcase;
}