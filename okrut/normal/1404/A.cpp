#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e5;
char Sym[N];
bool solve()
{
	int n, k;
	string s;
	cin>>n >>k >>s;
	rep(i,0,k) Sym[i] = '?';
	rep(i,0,n)
	{
		int r = i%k;
		if (Sym[r]=='?') Sym[r] = s[i];
		else
		{
			if (Sym[r]!=s[i] and s[i]!='?') return false;
		}
	}
	
	int zer = 0, jed = 0, q = 0;
	
	rep(i,0,n) if (s[i]=='?') s[i] = Sym[i%k];
	
	rep(i,0,k)
	{
		if (s[i]=='0') zer++;
		if (s[i]=='1') jed++;
		if (s[i]=='?') q++;
	}
	
	return (zer*2<=k and jed*2<=k);
	
}
int main ()
{
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	
	rep(q,0,t)
	{
		if (solve()) printf ("YES\n");
		else printf ("NO\n");
				
	}
	
}