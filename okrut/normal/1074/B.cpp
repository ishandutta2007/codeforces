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
vector <vector <int> > graf;
int n;
vector <bool> on, jej;
vector <int> her;
int closest (int a, int b=-1)
{
	if (on[a]) return a;
	int ret=1e9;
	for (int s: graf[a]) if (s!=b)
	{
		ret=min(ret, closest(s,a));
	}
	return ret;
}
void play ()
{
	on.clear();
	graf.clear();
	her.clear();
	jej.clear();
	cin>>n;
	graf.resize(n+1);
	on.resize(n+1, false);
	jej.resize(n+1, false);
	int a, b, k1, k2;
	rep(i,1,n)
	{
		cin>>a >>b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	cin>>k1;
	rep(i,0,k1) 
	{
		cin>>a;
		on[a]=true;
	}
	cin>>k2;
	her.resize(k2);
	rep(i,0,k2) 
	{
		cin>>her[i];
		jej[her[i]]=true;
	}
	cout<<"B " <<her[0] <<"\n";
	cout.flush();
	cin>>a;
	b=closest(a);
	cout<<"A " <<b <<"\n";
	cout.flush();
	cin>>a;
	if (jej[a]) cout<<"C " <<b <<"\n";
	else cout<<"C -1\n";
	cout.flush();
}
int main ()
{
	int t;
	cin>>t;
	rep(i,0,t) play();
}