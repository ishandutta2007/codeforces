#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SegTreeNode
{
	T val;
	// Lazy variables
	T add;
	SegTreeNode* l;
	SegTreeNode* r;
	
	SegTreeNode(T val_): val(val_), add(0), l(nullptr), r(nullptr) {}
	
	~SegTreeNode()
	{
		delete l;
		delete r;
		l = r = nullptr;
	}
};

// Add-sum implementation
template <class T>
struct SegTree
{
	using Node = SegTreeNode<T>;
	
	int n;
	Node* root;

	SegTree(int n_): n(n_)
	{
		// Default value
		root = new Node(0);
	}
	
	~SegTree()
	{
		delete root;
		root = nullptr;
	}
	
	void build(vector<T> const& vec) { build(vec, 0, n, root); }
	
	void build(vector<T> const& vec, int lb, int ub, Node* node)
	{
		if (ub == lb + 1)
		{
			node->val = vec[lb];
		}
		else
		{
			push(node, lb, ub);
			int mid = (lb + ub) / 2;
			build(vec, lb, mid, node->l);
			build(vec, mid, ub, node->r);
			// Merge
			node->val = max(node->l->val, node->r->val);
		}
	}
	
	void push(Node* node, int lb, int ub)
	{
		// Initialize default value
		if (!node->l)
			node->l = new Node(0);
		if (!node->r)
			node->r = new Node(0);
		// Lazy prop
		node->l->add += node->add;
		node->r->add += node->add;
		node->l->val += node->add;
		node->r->val += node->add;
		node->add = 0;
	}
	
	T query(int l, int r) { return query(l, r, 0, n, root); }
	
	T query(int l, int r, int lb, int ub, Node* node)
	{
		if (ub <= l || lb >= r)
			return -1E9; // No-op value
		if (lb >= l && ub <= r)
			return node->val;
		push(node, lb, ub);
		int mid = (lb + ub) / 2;
		// Merge
		return max(query(l, r, lb, mid, node->l), query(l, r, mid, ub, node->r));
	}
	
	void modify(int l, int r, T val) { modify(l, r, val, 0, n, root); }
	
	void modify(int l, int r, T val, int lb, int ub, Node* node)
	{
		if (ub <= l || lb >= r)
			return;
		if (lb >= l && ub <= r)
		{
			// Apply lazily
			node->add += val;
			node->val += val;
			return;
		}
		push(node, lb, ub);
		int mid = (lb + ub) / 2;
		modify(l, r, val, lb, mid, node->l);
		modify(l, r, val, mid, ub, node->r);
		// Merge
		node->val = max(node->l->val, node->r->val);
	}
};

const int MAXN = 3000;
vector<int> adjList[MAXN + 1];
int ans[MAXN + 1];
int d[MAXN + 1];
int par[MAXN + 1];
pair<int, int> leaves[MAXN + 1];
vector<int> baseVec;

pair<int, int> dfs(int v, int p, int d_ = 0, int left_ = 0)
{
	par[v] = p;
	d[v] = d_;
	bool leaf = true;
	int oldleft_ = left_;
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		leaf = false;
		left_ = dfs(adj, v, d_ + 1, left_).second;
	}
	if (leaf)
	{
		//cout << "LEAF " << v << endl;
		baseVec.push_back(d[v]);
		leaves[v] = {oldleft_, left_ + 1};
	}
	else
		leaves[v] = {oldleft_, left_};
	//cout << "dfs " << v << " " << leaves[v].first << " " << leaves[v].second << endl;
	return leaves[v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			adjList[i].clear();
		}
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		baseVec.clear();
		dfs(1, 1);
		//cout << "leaves " << leaves[1].second << endl;
		SegTree<int> seg(leaves[1].second);
		fill(ans + 1, ans + n + 1, *max_element(d + 1, d + n + 1));
		for (int i = 2; i <= n; i++)
		{
			seg.build(baseVec);
			int v = i;
			for (int j = 1; j < d[i]; j++)
			{
				seg.modify(leaves[v].first, leaves[v].second, -1);
				int ind = d[i] - j;
				int best = max(seg.query(0, leaves[1].second), d[i] - j + j / 2);
				ans[ind] = min(ans[ind], best); 
				//cout << i << " " << j << " " << seg.quer
				if (!(j & 1))
					v = par[v];
			}
		}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " \n"[i == n];
	}
	return 0;
}