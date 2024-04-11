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
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		int mini = 1.5e9, maks = 0;
		rep(i,0,n)
		{
			int a;
			scanf ("%d", &a);
			mini = min(mini, a);
			maks = max(maks, a);
		}
		
		int ret = (mini==maks)? n : 1;
		
		printf ("%d\n", ret);
	}
	
}