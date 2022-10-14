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
	ios_base::sync_with_stdio(false);
	string s;
	int t, n;
	cin>>t;
	rep(q,0,t)
	{
		cin >>n >>s;
		string res;
		res.resize(n, '0');
		bool ok = false;
		rep(p,'0','9'+1)
		{
			bool up = true, dob = true;
			string k1, k2;
			rep(i,0,n)
			{
				if (s[i]<p)
				{
					k1.pb(s[i]);
					res[i]='1';
				}
				if (s[i] > p)
				{
					up = false;
					k2.pb(s[i]);
					res[i]='2';
				}
				if (s[i]==p)
				{
					if (up) 
					{
						k2.pb(s[i]);
						res[i] = '2';
					}
					else 
					{
						k1.pb(s[i]);
						res[i] = '1';
					}
				}
			}
			k1 = k1 + k2;
			rep(i,1,n) if (k1[i-1] > k1[i]) dob = false;
			if (dob)
			{
				cout<<res <<"\n";
				ok = true;
				break;
			}
		}
		if (!ok) cout<<"-\n";
	}
}