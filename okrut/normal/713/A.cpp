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

map <string, int> mapa;

string pattern (ll a)
{
	string ret;
	ret.pb('#');
	int x=0;
	while (a>0)
	{
		if (a%2LL==0) x++;
		if (a%2LL==1) 
		{
			rep(i,0,x) ret.pb('0');
			x=0;
			ret.pb('1');
		}
		a/=10LL;
	}
	return ret;
}
int main ()
{
	int t;
	cin>>t;
	char c;
	ll n;
	string s;
	rep(i,0,t)
	{
		cin>>c;
		if (c=='?')
		{
			cin>>s;
			s.pb('#');
			reverse(s.begin(), s.end());
			while (s.back()=='0') s.pop_back();
			if (mapa.count(s)==0) cout<<"0\n";
			else cout<<mapa[s] <<"\n";
		}
		if (c=='+')
		{
			cin>>n;
			mapa[pattern(n)]++;
		}
		if (c=='-')
		{
			cin>>n;
			mapa[pattern(n)]--;
		}
	}
	
}