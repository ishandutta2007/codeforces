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

const int N = 1e5+10;

int ile[N];
vector <int> graf[N];
void dfs (int a, int d=0)
{
	ile[d]++;
	for (int s: graf[a]) dfs(s, d+1);
}
int main ()
{
	int n, p;
	scanf ("%d", &n);
	rep(i,2,n+1)
	{
		scanf ("%d", &p);
		graf[p].pb(i);
	}
	dfs(1);
	int res=0;
	rep(i,0,n) res+=ile[i]%2;
	printf ("%d\n", res);
}