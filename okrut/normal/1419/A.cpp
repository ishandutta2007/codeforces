#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

int solve()
{
	int n;
		string s;
		cin>>n >>s;
		
		if (n&1)
		{
			for (int i=0; i<n; i+=2) if ((s[i] - '0') & 1) return 1;
			return 2;
		}
		
		for (int i=1; i<n; i+=2) if (((s[i] - '0') & 1)==0) return 2;
		return 1;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(tc,0,t)
	{
		printf ("%d\n", solve());
		
	}
	
}