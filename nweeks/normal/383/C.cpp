#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

class Segment_tree
{
	public:
		Segment_tree(int n)
		{
			N = n;
			int seg_size = 1 << ((int)ceil(log2(n)) + 1);
			lazy.resize(seg_size);
			seg.resize(seg_size);
			fill(lazy.begin(), lazy.end(), 0);
			fill(seg.begin(), seg.end(), 0);
		}

		void __update(int node, int l, int r, int lo, int up, int val)
		{
			if (l > up or r < lo)
				return ;
			if (l >= lo and r <= up)
			{
				seg[node] += val;
				if (l != r)
				{
					lazy[2 * node + 1] += val;
					lazy[2 * node + 2] += val;
				}
				return ;
			}
			__update(2 * node + 1, l, (l+r)/2, lo, up, val);
			__update(2 * node + 2, (l + r) / 2 + 1, r, lo, up, val);
		}

		void update(int l, int r, int v)
		{
			__update(0, 0, N-1, l, r, v);
		}

		int __querry(int node, int l, int r, int ind)
		{
			if (lazy[node] != 0)
			{
				seg[node] += lazy[node];
				if (l != r)
				{
					lazy[2 * node + 1] += lazy[node];
					lazy[2 * node + 2] += lazy[node];
				}
				lazy[node] = 0;
			}
			if (l > ind or r < ind)
				return 0;
			if (l == r)
				return seg[node];
			return __querry(2*node+1, l,(l+r)/2, ind) + __querry(2*node+2,(l+r)/2+1,r,ind);
		}

		int querry(int ind)
		{
			return __querry(0, 0, N - 1, ind);
		}

	private:
		vector<int> seg;
		vector<int> lazy;
		int N;
};

int val[MAXN];
vector<int> G[MAXN];
int preorder[MAXN], postorder[MAXN];
int depth[MAXN];

int cur(0), N, Q;

void read_input(void)
{
	cin >> N >> Q;
	for (int i(0); i < N; ++i)
		cin >> val[i];

	for (int i(1); i < N; ++i)
	{
		int u, v; cin >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
}

void DFS(int u, int p, int d)
{
	preorder[u] = cur++;
	depth[u] = d;
	for (auto v : G[u])
		if (v != p)
			DFS(v, u, d + 1);
	postorder[u] = cur++;
}


int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read_input();
	DFS(0, 0, 0);

	Segment_tree seg = Segment_tree(cur);

	while (Q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int u, v; cin >> u >> v;
			u--;
			if (depth[u] % 2 == 1) v = -v;
			seg.update(preorder[u], postorder[u], v);
		}
		else
		{
			int u; cin >> u;
			--u;
			int v = seg.querry(preorder[u]);
			if (depth[u]%2 == 1)
				v = -v;
			cout << val[u] + v << '\n';
		}
	}
}