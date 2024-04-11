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
	
	solve(1);
}

int nb_jours;
int cur_sol;
set<pair<int, int> > segments; // Segments of working day

void del_seg(int l, int r)
{
	set<pair<int,int>>::iterator it;
	while ( l <= r and (it = segments.lower_bound({l, 0})) != segments.end()) 
	{
		int lo = it->second;
		int up = it->first;
		if (lo > r)
			break;
		segments.erase(it);
		cur_sol -= up-lo+1;
		l = max(l,lo);
		if (lo < l)
		{
			segments.insert(make_pair(l-1, lo));
			cur_sol += l-lo;
		}
		if (r < up)
		{
			segments.insert(make_pair(up, r+1));
			cur_sol += up-r;
		}
		l = up+1;
	}
}

void add_seg(int l, int r)
{
	set<pair<int,int>>::iterator it;
	while (l <= r and (it = segments.lower_bound({l, 0})) != segments.end())
	{
		int lo = it->second;
		int up = it->first;
		if (r < lo)
			break;
		segments.erase(it);
		cur_sol-=up-lo+1;
		int lo_add = min(lo, l);
		cur_sol += up-lo_add+1;
		segments.insert(make_pair(up, lo_add));
		l = up+1;
	}
	if (l <= r)
	{
		cur_sol+=r-l+1;
		segments.insert({r,l});
	}
}

void show_seg(void)
{
	cout << "-------------------" << endl;
	for (auto [r, l] : segments)
		cout << "(" << l << ", " << r << ") ";
	cout<<endl;
}

int solve(int testcase)
{
	int q;
	cin >> nb_jours >> q;

	segments.insert(make_pair(nb_jours, 1));
	cur_sol = nb_jours;
	
	while (q--)
	{
		int k, l, r;
		cin >> l >> r >> k;
		if (k==1)
			del_seg(l,r);
		else
			add_seg(l,r);
		//show_seg();
		cout << cur_sol<<'\n';
	}
	return testcase;
}