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
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

void solve(void)
{
	int n, k;
	read2(n,k);

	vector<int> a(k);
	readv(a);
	set<int> to_add;
	FOR(i,1,n+1)
		to_add.insert(i);
	vector<int> final_perm;
	int cur_want=1;
	stack<int> s;
	FORR(e, a)
	{
		while (SZ(s)>0 and s.top() < e)
		{
			if (cur_want != s.top())
			{
				pnl(-1);
				return ;
			}
			cur_want++;
			s.pop();
		}
		s.push(e);
		final_perm.pb(e);
	}
	for (int i(k); i < n; ++i)
	{
		while (SZ(s)>0 and cur_want == s.top())
		{
			s.pop();
			cur_want++;
		}
		if (SZ(s)>0)
		{
			auto it = to_add.lower_bound(s.top());
			--it;
			final_perm.pb(*it);
			s.push(*it);
			to_add.erase(it);
		}
		else
		{
			int add = *to_add.rbegin();
			s.push(add);
			final_perm.pb(add);
			to_add.erase(add);
		}
	}
	FORR(v, final_perm)
		pns(v);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	while (__t--)
		solve();
}