#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int Cnt[2];
vector <vector <int> > graf;
void dfs (int a, int b, int c)
{
	Cnt[c]++;
	for (int s: graf[a]) if (s!=b) dfs(s,a,1-c);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	graf.resize(n+1);
	rep(i,1,n)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	
	dfs(1,0,0);
	
	printf ("%d\n", min(Cnt[0], Cnt[1]) - 1);
}