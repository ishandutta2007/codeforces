#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi fist
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;
string t;
int n;
int main ()
{
	ios_base::sync_with_stdio(false);
	cin >>t;
	n = (int)t.size();
	string s;
	rep(i,0,n) if (t[i]!='a')
	{
		s.pb(t[i]);
	}
	bool ok = true;
	int m = (int)s.size();
	if (m%2==1) 
	{
		ok = false;
	}
	rep(i,0,m/2) if (s[i]!=s[i+m/2]) 
	{
		ok = false;
	}
	if (!ok)
	{
		cout<<":(\n";
		return 0;
	}
	
	int x=0;
	string res;
	rep(i,0,n)
	{
		if (t[i]=='a')
		{
			if (x>m/2) 
			{
				ok = false;
			}
			res.pb('a');
		}
		else
		{
			x++;
			if (x<=m/2) res.pb(t[i]);
		}
	}
	
	if (!ok)
	{
		cout<<":(\n";
		return 0;
	}
	cout<<res <<"\n";
}