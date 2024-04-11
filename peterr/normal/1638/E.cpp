#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Fenwick
{
	vector<T> vec;
	
	Fenwick(int n)
	{
		vec.resize(n);
	}
	
	void modify(int pos, T amt)
	{
		if (!pos)
		{
			vec[pos] += amt;
			return;
		}
		while (pos < (int) vec.size())
		{
			vec[pos] += amt;
			pos += pos & -pos;
		}
	}
	
	T sum(int pos)
	{
		T ans{};
		ans += vec[0];
		while (pos)
		{
			ans += vec[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
};

const int MAXN = 1E6;
long long lz[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	Fenwick<long long> fen(n + 2);
	map<int, int> mp;
	mp[1] = 1;
	while (q--)
	{
		string type;
		cin >> type;
		if (type == "Color")
		{
			int l, r, c;
			cin >> l >> r >> c;
			if (r != n)
				mp[r + 1] = (--mp.upper_bound(r + 1))->second;
			auto it = --mp.upper_bound(l);
			vector<int> nums;
			int cur = l;
			while (cur != r + 1)
			{
				int oldc = it->second;
				it++;
				int nxt = (it == mp.end() ? n + 1 : it->first);	
				nxt = min(nxt, r + 1);
				//cout << "updating " << cur << " to " << nxt << " from " << oldc << " to " << c << endl;
				fen.modify(cur, lz[oldc]);
				fen.modify(nxt, -lz[oldc]);
				fen.modify(cur, -lz[c]);
				fen.modify(nxt, lz[c]);
				cur = nxt;
				if (it != mp.end() && it->first <= r)
				{
					//cout << "erasing " << it->first << "\n";
					nums.push_back(it->first);
				}
			}
			for (int num : nums)
				mp.erase(num);
			mp[l] = c;
		}
		else if (type == "Add")
		{
			int c, x;
			cin >> c >> x;
			lz[c] += x;
		}
		else
		{
			int x;
			cin >> x;
			int c = (--mp.upper_bound(x))->second;
			cout << fen.sum(x) + lz[c] << "\n";
		}
	}
	return 0;
}