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
	int n, m;
	cin>>n>>m;
	std::vector<bool> r(n, true);
	std::vector<bool> c(n, true);
	int x, y;
	r[0] = false;
	c[0] = false;
	r[n-1] = false;
	c[n-1] = false;
	int total = 2*n - 4;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		x--; y--;
		if(r[x]){
			r[x] = false;
			total--;
		}
		if(c[y]){
			c[y] = false;
			total--;
		}
	}
	if(n&1)
	{
		if(r[(n-1)/2] && c[(n-1)/2])
			total--;
	}
	cout<<total;
}