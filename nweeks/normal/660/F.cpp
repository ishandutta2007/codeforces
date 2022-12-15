#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

using T = __int128; // T must be such that values can't overflow.
struct Line
{
	ll a, b;
	Line(ll a, ll b) : a(a), b(b) {}
	T get(ll x) { return a * T(x) + b;}
};

struct Node
{
	Node *l = 0, *r = 0;
	Line line; ll lo, hi;

	Node(Line l, ll lo, ll hi) : line(l), lo(lo), hi(hi) {}

	void add(Line addL)
	{
		if (addL.get(lo) > line.get(lo)) swap(line, addL);
		if (addL.get(hi) <= line.get(hi)) return;
		if (lo == hi) return ;
		ll mid = lo + (hi - lo)/2;
		if (line.get(mid) > addL.get(mid))
		{
			if (!r) r = new Node(line, mid+1, hi);
			r->add(addL);
		}
		else
		{
			swap(line, addL);
			if (!l) l = new Node(line, lo, mid);
			l->add(addL);
		}
	}

	T get(ll x)
	{
		if (lo == hi) return line.get(x);
		ll mid = lo + (hi - lo) / 2;
		if (mid >= x)
			return l ? max(line.get(x), l->get(x)) : line.get(x);
		return r ? max(line.get(x), r->get(x)) : line.get(x);
	}
};

struct LiChao
{
	ll lo, up; Node *root;

	LiChao(ll lo, ll up) : lo(lo), up(up), root(0) {}

	void add(Line line)
	{
		if (!root) root = new Node(line, lo, up);
		else root->add(line);
	}

	ll get(ll x) { return ll(root->get(x));}
};

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbRolls;
	cin >> nbRolls;
	LiChao lichao(-1e18, 1e18);
	vector<int> rolls(nbRolls);
	for (auto &v : rolls)
		cin >> v;
	vector<ll> prefixSum(nbRolls);
	vector<ll> prefixSum2(nbRolls);
	prefixSum2[0] = prefixSum[0] = rolls[0];
	for (ll i(0); i+1 < nbRolls; ++i)
	{
		prefixSum[i+1] = prefixSum[i] + rolls[i+1];
		prefixSum2[i+1] = (i+2) * rolls[i+1] + prefixSum2[i];
	}
	ll ans(0);
	for (int i(0); i < nbRolls; ++i)
	{
		ll a = -i;
		ll b = 0;
		if (i)
			b = i * prefixSum[i-1] - prefixSum2[i-1] ;
		lichao.add(Line(a,b));
		ll val = prefixSum2[i] + lichao.get(prefixSum[i]);
		ans = max(ans, val);
	}
	cout << ans << endl;
}