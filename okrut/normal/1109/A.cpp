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

const int M = 1<<20;
int ile[M][2];

int main ()
{
	int n;
	scanf ("%d", &n);
	int stan=0;
	ile[0][1]++;
	rep(i,0,n)
	{
		int a;
		scanf ("%d", &a);
		stan^=a;
		ile[stan][i%2]++;
	}
	ll res=0LL;
	rep(i,0,M) rep(j,0,2) res+=ll(ile[i][j]) * ll(ile[i][j]-1);
	printf ("%lld\n", res/2LL);
}