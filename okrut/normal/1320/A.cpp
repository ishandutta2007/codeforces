#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int M = 1e6;
ll Sum[M+M];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	
	rep(i,1,n+1)
	{
		int b;
		scanf ("%d", &b);
		
		Sum[M+(i-b)] += ll(b);
	}
	
	ll res = 0;
	rep(i,0,M+M) res = max(res, Sum[i]);
	printf ("%lld\n", res); 
	
}