#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

int len, nbVoulus;
string s;
vector<int> sa, _ws, x, y;

void suffixArray(const string& t, int lim=256)
{
	int n = SZ(t) + 1, k = 0, a, b;
	x.resize(SZ(t));
	for (int i(0); i < SZ(t); ++i) x[i] = t[i];
	x.push_back(0);
	y.assign(n, 0);
	_ws.resize(max(n, lim));
	sa = y;
	iota(sa.begin(), sa.end(), 0);
	for (int j(0), p(0); p < n; j = max(1, j * 2), lim = p)
	{
		p=j, iota(y.begin(), y.end(), n-j);
		for (int i(0); i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		fill(_ws.begin(), _ws.end(), 0);
		for (int i(0); i < n; ++i) _ws[x[i]]++;
		for (int i(1); i < lim; ++i) _ws[i] += _ws[i-1];
		for (int i(n); i--;) sa[--_ws[x[y[i]]]] = y[i];
		swap(x,y), p = 1, x[sa[0]] = 0;
		for (int i(1); i < n; ++i) a = sa[i-1], b = sa[i], x[b] =
					(y[a] == y[b] && y[a+j] == y[b+j]) ? p-1 : p++;
	}
	vector<int> tmp;
	for (auto v : sa)
		if (v + nbVoulus <= len)
			tmp.push_back(v);
	sa = move(tmp);
}


struct Node
{
	int lft, rgt;
	int lo, up;
	int pos;
	bool isOK = false;
	Node(int lo, int up, int pos) : pos(pos), lo(lo), up(up), lft(-1), rgt(-1){}
};

vector<Node> nodes;

void build(int curNode)
{
	if (nodes[curNode].pos == nbVoulus)
		return ;
	if (nodes[curNode].lo == nodes[curNode].up)
	{
		nodes[curNode].isOK = true;
		return;
	}
	int l(nodes[curNode].lo), r(nodes[curNode].up);
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (s[nodes[curNode].pos + sa[mid]] == '1')
			r = mid;
		else l = mid+1;
	}
	if (s[nodes[curNode].pos + sa[l]] == '1')
	{
		nodes.emplace_back(l, nodes[curNode].up, nodes[curNode].pos+1);
		nodes[curNode].rgt = SZ(nodes)-1;
		build(nodes[curNode].rgt);
		nodes[curNode].isOK |= nodes[nodes[curNode].rgt].isOK;
	}
	else
		nodes[curNode].isOK = true;
	if (nodes[curNode].isOK) return ;
	if (l > nodes[curNode].lo)
	{
		nodes.emplace_back(nodes[curNode].lo, l-1, nodes[curNode].pos+1);
		nodes[curNode].lft = SZ(nodes)-1;
		build(nodes[curNode].lft);
		nodes[curNode].isOK |= nodes[nodes[curNode].lft].isOK;
	}
	else
		nodes[curNode].isOK = true;
	
}


void solve(void)
{
	cin >> len >> nbVoulus;
	cin >> s;
	suffixArray(s);
	nodes.clear();
	nodes.emplace_back(0, len-nbVoulus, 0);
	build(0);
	if (!nodes[0].isOK)
	{
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	int curNode(0);
	for (int i(0); i < nbVoulus; ++i)
	{
		if (curNode==-1)
		{
			cout << 0;
			continue;
		}
		if (nodes[curNode].lo == nodes[curNode].up)
		{
			int cur(i);
			int startPos = sa[nodes[curNode].lo];
			while (cur+1 < nbVoulus and s[startPos + cur] == '1')
			{
				cout << 0;
				++cur;
			}
			if (cur + 1 == nbVoulus and s[startPos+cur] == '1')
			{
				cout << 1;
				++cur;
			}
			while (cur < nbVoulus)
			{
				cout << 0;
				++cur;
			}
			cout << '\n';
			return ;
		}
		if (nodes[curNode].rgt == -1 or nodes[nodes[curNode].rgt].isOK)
		{
			cout << 0;
			curNode = nodes[curNode].rgt;
		}
		else
		{
			cout << 1;
			curNode = nodes[curNode].lft;
		}
	}
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}