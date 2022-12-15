#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

void solve(void)
{
	string s;
	read(s);
	int n = s.size();

	queue<int> Q[10];
	
	FOR(i,0,n)
		Q[s[i]-'0'].push(i);

	for (int i(0); i < n; ++i)
	{
		int even(-1);
		int odd(-1);
		FOR(k,0,10)
		{
			if (Q[k].empty()) continue;
			if (k%2==1)
			{
				if (odd == -1 or Q[k].front() < Q[odd].front())
					odd = k;
			}
			else
			{
				if (even == -1 or Q[k].front() < Q[even].front())
					even = k;
			}
		}

		if (even == -1)
		{
			cout << odd;
			Q[odd].pop();
		}
		else if (odd == -1)
		{
			cout << even;
			Q[even].pop();
		}
		else
		{
			even = min(even, odd);
			Q[even].pop();
			cout << even;
		}

/*		int which = -1;
		FOR(k,0,10)
			if (not Q[k].empty())
			{
				if (which == -1 or Q[which].front() > Q[k].front())
					which = k;
			}
		int pot = -1;
		for (int k(0); k < which; ++k)
		{
			if (k%2 == which%2) continue;
			if (Q[k].empty()) continue;
			if (pot == -1 or Q[pot].front() > Q[k].front())
				pot = k;
		}

		if (pot != -1)
			which = pot;
		cout << which;
		Q[which].pop();*/
	}
	cout << '\n';
}


int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	read(q);
	while (q--)
		solve();
}