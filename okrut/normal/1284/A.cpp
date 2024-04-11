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
	int n, m;
	cin>>n >>m;
	
	vector <string> sn(n), sm(m);
	
	for (string &s: sn) cin>>s;
	for (string &s: sm) cin>>s;
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int a;
		cin>>a;
		a--;
		cout<<sn[a%n] <<sm[a%m] <<"\n";
	}
}