#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int min_value;
	Node *go[2];

	Node(void)
	{
		min_value = 1e9;
		go[0] = go[1] = nullptr;
	}
};

const int MAX = 1e5 + 1;
const int MAXK = 18;

vector<Node *> trie(MAX);

void insert(int which, int val)
{
	Node *cur = trie[which];
	cur->min_value = min(cur->min_value, val);

	for (int k(MAXK-1); k >= 0; --k)
	{
		int bit = !!((1<<k) & val);
		if (cur->go[bit] == nullptr)
			cur->go[bit] = new Node();
		cur = cur->go[bit];
		cur->min_value = min(cur->min_value, val);
	}
}

int get(int which, int val, int v)
{
	Node *cur = trie[which];

	if (cur->min_value > val)
		return -1;
	int ans(0);
	for (int k(MAXK-1); k >= 0; --k)
	{
		if ((1<<k) & v)
		{
			if (cur->go[0] != nullptr)
			{
				ans *= 2;
				cur = cur->go[0];
			}
			else
			{
				ans = ans * 2 + 1;
				cur = cur->go[1];
			}
		}
		else
		{
			if (cur->go[1] != nullptr and cur->go[1]->min_value <= val)
			{
				ans = ans * 2 + 1;
				cur = cur->go[1];
			}
			else
			{
				ans = ans * 2;
				cur = cur->go[0];
			}
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	int q;
	cin >> q;
	
	for (int i(0); i < MAX; ++i)
	{
		trie[i] = new Node();
		trie[i]->go[0] = trie[i]->go[1] = nullptr;
		trie[i]->min_value = 1e9;
	}

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int val;
			cin >> val;
			for (int i(1); i*i <= val; ++i)
				if (val%i==0)
				{
					insert(i, val);
					insert(val/i, val);
				}
		}
		else
		{
			int x, k, s;
			cin >> x >> k >> s;
			int ans(-1);
			
			if (x % k != 0)
				cout << -1 << '\n';
			else
				cout << get(k, s-x, x) << '\n';
		}
	}
}