#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+1;
int Pos[N];

bool check (int n)
{
	int q = 1;
	int last = n;
	while (q<=n)
	{
		int st = Pos[q];
		int p = Pos[q];
		while (Pos[q]+1<last)
		{
			if (Pos[q+1]!=p+1) return false;
			q++;
			p++;
		}
		q++;
		last = st;
	}
	
	return true;
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		rep(i,0,n)
		{
			int a;
			scanf ("%d", &a);
			Pos[a] = i;
		}
		
		if (check(n)) printf ("Yes\n");
		else printf ("No\n");
		
	}
	
}