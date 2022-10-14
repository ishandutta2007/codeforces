#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int tests;
	cin>>tests;
	rep(q,0,tests)
	{
		int n, k;
		string s, t;
		cin>>n >>k >>s;
		rep(i,0,k-1) 
		{
			t.pb('(');
			t.pb(')');
		}
		rep(i,k-1,n/2) 
		{
			t.pb('(');
		}
		rep(i,k-1,n/2)
		{
			t.pb(')');
		}
		
		vector <pair <int, int> > res;
		rep(i,0,n) if (s[i]!=t[i])
		{
			int l = i, r=i;
			while (s[r]!=t[i]) r++;
			res.pb(mp(l+1, r+1));
			
			int d = (r-l+1)/2;
			rep(j,0,d) swap(s[l+j], s[r-j]);
		}
		printf ("%d\n", (int)res.size());
		for (auto p: res) printf ("%d %d\n", p.fi, p.se);
	}
}