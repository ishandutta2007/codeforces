#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int n;
std::vector<string> s;
std::vector<std::vector<int> > st(300*300);
std::vector<std::vector<int> > ene(300*300);
std::vector<int> siz(300*300);
std::vector<int> c(300*300, 0);
std::vector<int> en;
std::vector<int> sta;
std::vector<int> nex;
std::vector<int> pre;
// std::vector<bool> vis;
string res;

int dfs(int i, int p)
{
	c[sta[i]]++;
	pre[i] = p;
	if(c[en[i]] == siz[en[i]])
		return i;
	int sa = st[en[i]][c[en[i]]];
	nex[i] = sa;
	int e = dfs(sa, i);
	if(en[e] != en[i] && c[en[i]] != siz[en[i]])
	{
		int sa2 = st[en[i]][c[en[i]]];
		nex[i] = sa2;
		pre[sa] = dfs(sa2, i);
		nex[pre[sa]] = sa;
	}
	return e;
}
void Print(int i)
{
	res += s[i].substr(1, 1);
	if(nex[i] != -1)
		Print(nex[i]);
	else
		res += s[i].substr(2, 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> n;
	s.resize(n);
	nex.resize(n, -1);
	sta.resize(n, -1);
	pre.resize(n, -1);
	en.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		sta[i] = s[i][0]*300+s[i][1];
		st[sta[i]].pb(i);
		en[i] = s[i][1]*300+s[i][2];
		ene[en[i]].pb(i);
	}
	for (int i = 0; i < 300*300; ++i)
		siz[i] = st[i].size();
	std::vector<int> sta;
	for (int u = 0; u < 300*300; ++u)
	{
		int t1 = st[u].size();
		int t2 = ene[u].size();
		for (int i = 0; i < t1 - t2; ++i)
			sta.pb(st[u][i]);
	}
	if(sta.size() > 1)
	{
		cout << "NO";
		exit(0);
	}
	int p = 0;
	if(sta.size() == 1)
		p = sta[0];
	dfs(p, -1);
	res = "" + s[p].substr(0, 1);
	Print(p);
	if(res.size() != (n + 2))
		cout << "NO";
	else
		cout << "YES\n" << res;
}