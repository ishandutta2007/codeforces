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
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		c[i] *= (n - i);
	}
	sort(c.begin(), c.end());
	print(c);
	int i;
	for (i = 0; i < n; ++i)
	{
		print(x, i, c[i]);
		if(x < c[i]) 
			break;
		else
			x -= c[i];
	}
	cout << i;
}