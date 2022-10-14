#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
vector <int> hory;
vector <int> ver;
int n, m;
int main ()
{
	scanf ("%d %d", &n, &m);
	ver.resize(n);
	int mini=1e9;
	int stan=0;
	rep(i,0,n) scanf ("%d", &ver[i]);
	int a, b, c;
	rep(i,0,m)
	{
		scanf ("%d %d %d", &a, &b, &c);
		if (a!=1) continue;
		hory.pb(b);
	}
	int x=0;//ile moge wyminac
	m=hory.size();
	sort(hory.begin(), hory.end());
	sort(ver.begin(), ver.end());
	rep(i,0,n)
	{
		while (x<m && hory[x]<ver[i]) x++;
		mini=min(mini, i+m-x);
	}
	while (x<m && hory[x]<1e9) x++;
	mini=min(mini, n+m-x);
	printf ("%d\n", mini);
}