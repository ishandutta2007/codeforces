#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

std::vector<int> segtree;

void build(int node, int start, int end)
{
	if(start == end)
		segtree[node] = 1;
	else {
		int mid = (start + end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid + 1, end);
		segtree[node] = end - start + 1;
	}
}

void update(int node, int start, int end, int i)
{
	if(start > i || end < i)
		return;
	if(start == end)
		segtree[node]--;
	else {
		int mid = (start + end)/2;
		update(2*node, start, mid, i);
		update(2*node+1, mid + 1, end, i);
		segtree[node]--;
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(l <= start && end <= r)
		return segtree[node];
	else if(end < l || start > r)
		return 0;
	else {
		int mid = (start + end)/2;
		return (query(2*node, start, mid, l, r)+query(2*node+1, mid + 1, end, l, r));
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n, k;
	cin >> n >> k;
	segtree.resize(4*n);
	build(1, 0, n-1);
	std::vector<ll> a(n);
	std::vector<std::pair<ll, int> > b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[i] = mp(a[i], i);
	}
	sort(b.begin(), b.end());
	ll i;
	std::vector<bool> l(n, true);
	print(b);
	for (i = 0; i < n; ++i)
	{
		std::pair<ll, int> p = b[i];
		ll r = ((k / (n - i)) + ((k % (n - i) >= query(1, 0, n-1, 0, p.second)) ? 1 : 0));
		print(k, p, r, n-i);
		if(p.first <= r) {
			l[p.second] = false;
			update(1, 0, n-1, p.second);
			k -= p.first;
		}
		else
			break;
	}
	std::vector<int> v;
	for (int j = 0; j < n; ++j)
	{
		if(l[j])
			v.pb(j);
	}
	if(k == 0 && v.size() == 0)
	{

	}
	else if(v.size() == 0)
		cout << -1;
	else {
		int siz = v.size();
		int curr = k % siz;
		for (int j = 0; j < siz; ++j)
		{
			cout << v[curr] + 1 << " ";
			curr++;
			if(curr == siz)
				curr = 0;
		}
	}
}