#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
std::vector<std::vector<int> > seg;
string s;
void build(int node, int st, int en)
{
	if(st == en)
	{
		if(s[st] == '(')
			seg[node][2] = 1;
		else
			seg[node][1] = 1;
		return;
	}
	int mid = (st + en)/2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);
	seg[node][0] = seg[2 * node][0] + seg[2 * node + 1][0] + min(seg[2 * node][2], seg[2 * node + 1][1]);
	seg[node][1] = seg[2 * node][1] + seg[2 * node + 1][1] - min(seg[2 * node][2], seg[2 * node + 1][1]);
	seg[node][2] = seg[2 * node][2] + seg[2 * node + 1][2] - min(seg[2 * node][2], seg[2 * node + 1][1]);
}

std::pair<int, std::pair<int, int> > query(int node, int st, int en, int l, int r)
{
	if(en < l || st > r)
		return mp(0, mp(0, 0));
	else if(st >= l && en <= r)
		return mp(seg[node][0], mp(seg[node][2], seg[node][1]));
	int mid = (st + en) >> 1;
	auto p1 = query(2*node, st, mid, l, r);
	auto p2 = query(2*node + 1, mid + 1, en, l, r);
	return mp(p1.f + p2.f + min(p1.s.f, p2.s.s), mp(p1.s.f + p2.s.f - min(p1.s.f, p2.s.s), p1.s.s + p2.s.s - min(p1.s.f, p2.s.s)));
}

int log2n(int siz)
{
	int r = 0;
	while(siz)
		siz >>= 1, r++;
	return r;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> s;
	seg.resize(1<<(log2n(s.size())+1)+1, std::vector<int> (3, 0));
	build(1, 0, s.size() - 1);
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		cout << 2*((query(1, 0, s.size()-1, l-1, r-1)).f) << "\n";
	}
}