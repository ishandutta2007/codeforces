#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *left, *right;
	int lb, ub;
	int a, b, c, ab, bc, abc;
	
	Node(int lb, int ub) : left(nullptr), right(nullptr), lb(lb), ub(ub)
	{
		a = b = c = ab = bc = abc = 0;
	}
	
	void push()
	{
		if (!left)
		{
			int mid = (lb + ub) / 2;
			left = new Node(lb, mid);
			right = new Node(mid + 1, ub);
		}
	}
	
	void upd(int pos, char ch)
	{
		if (lb == pos && ub == pos)
		{
			a = b = c = 0;
			if (ch == 'a')
				a = 1;
			else if (ch == 'b')
				b = 1;
			else
				c = 1;
		}
		else
		{
			push();
			int mid = (lb + ub) / 2;
			if (pos <= mid)
				left->upd(pos, ch);
			else
				right->upd(pos, ch);
			a = left->a + right->a;
			b = left->b + right->b;
			c = left->c + right->c;
			ab = min(left->ab + right->b, left->a + right->ab);
			bc = min(left->bc + right->c, left->b + right->bc);
			abc = left->abc + right->c;
			abc = min(abc, left->ab + right->bc);
			abc = min(abc, left->a + right->abc);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	string s;
	cin >> n >> q >> s;
	Node root(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		root.upd(i, s[i]);
	}
	while (q--)
	{
		int ind;
		char ch;
		cin >> ind >> ch;
		ind--;
		root.upd(ind, ch);
		cout << root.abc << "\n";
	}
	return 0;
}