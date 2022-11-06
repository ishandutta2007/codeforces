#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int m; cin >> m;
	std::vector<std::set<int> > adjcolor(100001);
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		adjcolor[c[i]].insert(-1);
	}
	for (int i = 0; i < m; ++i)
	{
		int x; cin >> x;
		int y; cin >> y;
		x--; y--;
		if(c[x] != c[y]) {
			adjcolor[c[x]].insert(c[y]);
			adjcolor[c[y]].insert(c[x]);
		}
	}
	int max = -1;
	int C = -1;
	for (int i = 0; i < 100001; ++i)
	{
		int s = adjcolor[i].size();
		if(s > max){
			max = s;
			C = i;
		}
	}
	print(C, max);
	cout<<C;
}