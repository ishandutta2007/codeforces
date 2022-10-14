#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define miitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
const ll mod = 1234567891;
const ll pod=29;
vector <ll> pot, hasze;
string s, t;
int n;
ll hasz (int from, int to)
{
	return (mod+hasze[to]-(hasze[from]*pot[to-from])%mod)%mod;
}
bool check (int a, int b) //dlugosc zera i jedynki
{
	int pos=0; //1 przed
	ll zer=-1;
	ll jed=-1;
	int w; //przesuniecie dla jedynek
	rep(i,0,(int)s.size())
	{
		if (s[i]=='0')
		{
			if (zer==-1)
			{
				zer=hasz(pos,pos+a);
			}
			else
			{
				if (zer!=hasz(pos,pos+a)) 
				{
					return false;
				}
			}
			pos+=a;
			
		}
		if (s[i]=='1')
		{
			if (jed==-1)
			{
				jed=hasz(pos, pos+b);
			}
			else
			{
				if (jed!=hasz(pos,pos+b)) return false;
			}
			pos+=b;
		}
	}
	if (jed==zer) return false;
	return true;
}
int main ()
{
	cin>>s >>t;
	ll zeros=0, ones=0;
	rep(i,0,(int)s.size())
	{
		if (s[i]=='1') ones++;
		if (s[i]=='0') zeros++;
	}
	n=(int)t.size();
	pot.resize(n+1,1);
	rep(i,1,n+1) pot[i]=(pot[i-1]*pod)%mod;
	hasze.resize(n+1,0);
	rep(i,1,n+1) hasze[i]=(hasze[i-1]*pod+t[i-1]-'a'+1)%mod;
	
	
	//d - dlugosc zer
	int res=0;
	for (ll d=1; d*zeros<(ll)n; d++) if ((n-d*zeros)%ones==0)
	{
		debug ("check %d %d\n", (int)d, (n-d*zeros)/ones);
		if (check (d,(n-d*zeros)/ones)) res++;
	}
	printf ("%d\n", res);
}