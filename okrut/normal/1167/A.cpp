#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

bool ok (string s)
{
	int c=0;
	for (int i=(int)s.size()-1; i>=0; i--)
	{
		if (s[i]>='0' && s[i]<='9') c++;
		if (c>10 && s[i]=='8') return true;
	}
	return false;
}
int main ()
{
	int t, n;
	cin>>t;
	string s;
	rep(i,0,t)
	{
		cin>>n;
		cin>>s;
		if (ok(s)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}