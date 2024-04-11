#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

vector <vector <int> > graf;
vector <bool> vst;
vector <int> cap;
int n, m, k;
int dfs (int a)
{
	int ret=1;
	vst[a] = false;
	for (int s: graf[a]) if (vst[s]) ret+=dfs(s);
	return ret;
}
int main ()
{
	scanf ("%d %d %d", &n, &m, &k);
	graf.resize(n+1);
	vst.resize(n+1, true);
	cap.resize(k);
	rep(i,0,k) scanf ("%d", &cap[i]);
	int a, b;
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int maks = 0;
	int kraw=0;
	for (int x: cap) 
	{
		a = dfs(x);
		maks = max(maks, a);
		kraw += (a * (a-1))/2;
	}
	rep(i,1,n+1) if (vst[i])
	{
		kraw +=maks;
		maks++;
	}
	printf ("%d\n", kraw - m);
}