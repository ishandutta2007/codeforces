#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
pair <ll, ll> pkt (ll a) //wzroc punkt nr 10
{
	ll y=a/50; //segment duzy
	a%=50;
	ll x=y*10+a/5; //podsegment
	y+=a%5+1;
	return mp(x, y);
}
int n;
string s;
void binsuche (ll lewy=50, ll prawy=5e9)
{
	pair <ll, ll> p;
	if (n>0)
	{
		n--;
		p=pkt(mitte);
		cout<<p.fi <<" " <<p.se <<"\n";
		cout << flush;
		cin>>s;
		if (s=="black") binsuche (mitte, prawy);
		else binsuche (lewy, mitte);
	}
	else
	{
		p=pkt(mitte);
		cout<<p.fi <<" " <<p.se <<" " <<p.fi-1 <<" " <<p.se+10 <<"\n";
		cout << flush;
	}
}
int main ()
{
	cin>>n;
	binsuche();
}