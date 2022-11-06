#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

ll p1 = 1511;
ll p2 = 1523;
std::vector<string> s;
int n, m;

int p[] = {-1, 0, 1, 0};
int q[] = {0, 1, 0, -1};

std::vector<std::vector<int> > lvl;
std::vector<std::vector<bool> > vis1;
std::vector<std::vector<bool> > vis2;

void dfs1(int x, int y, ll lv)
{
	if(s[x][y] == '#')
		return;
	vis1[x][y] = true;
	lvl[x][y] = lv;
	int i = x + p[0];
	int j = y + q[0];
	ll tlv = lv;
	if(i < 0)
	{
		i = n-1;
		tlv += p1;
	}
	if(!vis1[i][j])
		dfs1(i, j, tlv);
	
	i = x + p[1];
	j = y + q[1];
	tlv = lv;
	if(j == m)
	{
		j = 0;
		tlv += p2;
	}
	if(!vis1[i][j])
		dfs1(i, j, tlv);
	
	i = x + p[2];
	j = y + q[2];
	tlv = lv;
	if(i == n)
	{
		i = 0;
		tlv -= p1;
	}
	if(!vis1[i][j])
		dfs1(i, j, tlv);
	
	i = x + p[3];
	j = y + q[3];
	tlv = lv;
	if(j < 0)
	{
		j = m-1;
		tlv -= p2;
	}
	if(!vis1[i][j])
		dfs1(i, j, tlv);
}

bool dfs2(int x, int y, ll lv)
{

	if(s[x][y] == '#')
		return false;
	
	bool u = false;
	vis2[x][y] = true;
	u = u|((bool)(lv != lvl[x][y]));
	
	int i = x + p[3];
	int j = y + q[3];
	ll tlv = lv;
	if(j < 0)
	{
		j = m-1;
		tlv -= p2;
	}
	if(!vis2[i][j])
		u = u|dfs2(i, j, tlv);
	
	i = x + p[2];
	j = y + q[2];
	tlv = lv;
	if(i == n)
	{
		i = 0;
		tlv -= p1;
	}
	if(!vis2[i][j])
		u = u|dfs2(i, j, tlv);

	i = x + p[1];
	j = y + q[1];
	tlv = lv;
	if(j == m)
	{
		j = 0;
		tlv += p2;
	}
	if(!vis2[i][j])
		u = u|dfs2(i, j, tlv);

	i = x + p[0];
	j = y + q[0];
	tlv = lv;
	if(i < 0)
	{
		i = n-1;
		tlv += p1;
	}
	if(!vis2[i][j])
		u = u|dfs2(i, j, tlv);
	
	return u;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> n >> m;
	s.resize(n);
	lvl.resize(n, std::vector<int> (m));
	vis2.resize(n, std::vector<bool> (m, false));
	vis1.resize(n, std::vector<bool> (m, false));
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int sx;
	int sy; 
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if(s[i][j] == 'S'){
				sx = i;
				sy = j;
			}
	s[sx][sy] = '.';
	dfs1(sx, sy, 0);
	bool res = dfs2(sx, sy, 0);

	if(res || (n == 1 && m == 1))
		cout << "Yes";
	else
		cout << "No";
}