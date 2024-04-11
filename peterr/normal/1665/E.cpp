#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SegTreeNode
{
	T val;
	SegTreeNode* l;
	SegTreeNode* r;
	
	SegTreeNode(T val_): val(val_), l(nullptr), r(nullptr) {}
	
	~SegTreeNode()
	{
		delete l;
		delete r;
		l = r = nullptr;
	}
};

template <class T, class Merge, class Default>
struct SegTree
{
	using Node = SegTreeNode<T>;
	
	int n;
	const Merge merge;
	const Default def;
	Node* root;

	SegTree(int n_): n(n_), merge(Merge()), def(Default())
	{
		root = new Node(def());
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
			push(node);
			int mid = (lb + ub) / 2;
			build(vec, lb, mid, node->l);
			build(vec, mid, ub, node->r);
			node->val = merge(node->l->val, node->r->val);
		}
	}
	
	void push(Node* node)
	{
		if (!node->l)
			node->l = new Node(def());
		if (!node->r)
			node->r = new Node(def());
	}
	
	T query(int l, int r) { return query(l, r, 0, n, root); }
	
	T query(int l, int r, int lb, int ub, Node* node)
	{
		if (ub <= l || lb >= r)
			return def();
		if (lb >= l && ub <= r)
			return node->val;
		push(node);
		int mid = (lb + ub) / 2;
		return merge(query(l, r, lb, mid, node->l), query(l, r, mid, ub, node->r));
	}
};

void printVec(vector<pair<int, int>> const& vec)
{
	for (pair<int, int> pr : vec)
		cout << " (" << pr.first << ", " << pr.second << ")";
}

const int MAXN = 1E5;
const int LOG = 30;
int a[MAXN];

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
		vector<vector<pair<int, int>>> vec(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			vec[i] = {{a[i], 1}};
		}
		SegTree<
			vector<pair<int, int>>,
			decltype([](vector<pair<int, int>> const& lhs, vector<pair<int, int>> const& rhs)
			{
				//cout << "mergin\n";
				//printVec(lhs);
				//cout << endl;
				//printVec(rhs);
				//cout << endl;
				vector<pair<int, int>> dst;
				int ptr1 = 0;
				int ptr2 = 0;
				while (ptr1 < (int) lhs.size() && ptr2 < (int) rhs.size())
				{
					pair<int, int> pr1 = lhs[ptr1];
					pair<int, int> pr2 = rhs[ptr2];
					if (pr1.first == pr2.first)
					{
						dst.push_back({pr1.first, pr1.second + pr2.second});
						ptr1++;
						ptr2++;
					}
					else if (pr1.first < pr2.first)
					{
						dst.push_back(pr1);
						ptr1++;
					}
					else
					{
						dst.push_back(pr2);
						ptr2++;
					}
				}
				while (ptr1 < (int) lhs.size())
					dst.push_back(lhs[ptr1++]);
				while (ptr2 < (int) rhs.size())
					dst.push_back(rhs[ptr2++]);
				//printVec(dst);
				//cout << endl;
				vector<pair<int, int>> res;
				int lo = 0;
				int hi = (int) dst.size() - 1;
				for (int i = LOG - 1; i >= 0; i--)
				{
					if ((dst[lo].first >> i) & 1)
						continue;
					if (((dst[hi].first >> i) & 1) == 0)
						continue;
					//cout << "here " << i << " " << lo << " " << hi << endl;
					if (dst[lo].second == 1 && ((dst[lo + 1].first >> i) & 1))
					{
						//cout << "in loop pushing index " << lo << endl;
						res.push_back(dst[lo]);
						lo++;
					}
					else
					{
						while ((dst[hi].first >> i) & 1)
							hi--;
					}
				}
				res.push_back(dst[lo]);
				//cout << "pushing index " << lo << endl;
				//cout << "res" << endl;
				//printVec(res);
				//cout << endl;
				return res;
			}),
			decltype([](){return vector<pair<int, int>>();})
		> tree(n);
		tree.build(vec);
		int q;
		cin >> q;
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			//cout << "query " << l << " " << r << endl;
			l--;
			r--;
			vector<pair<int, int>> check = tree.query(l, r + 1);
			int ans = 1 << 30;
			//cout << "here\n";
			for (int i = 0; i < (int) check.size(); i++)
			{
				//cout << check[i].first << " \n"[i == (int) check.size() - 1];
				if (check[i].second > 1)
					ans = min(ans, check[i].first);
				for (int j = i + 1; j < (int) check.size(); j++)
				{
					ans = min(ans, check[i].first | check[j].first);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}