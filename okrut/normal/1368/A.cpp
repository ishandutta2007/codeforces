#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int a, b, n;
		scanf ("%d %d %d", &a, &b, &n);
		int cnt = 0;
		while (a<=n and b<=n)
		{
			if (a > b) b+=a;
			else a+=b;
			cnt++;
		}
		printf ("%d\n", cnt);
	}
}