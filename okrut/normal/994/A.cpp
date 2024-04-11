#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
int n, t, m;
vector <int> ciag, tab;

int main ()
{
	int a, b;	
	cin >>n >>m;
	tab.resize(10, 0);
	ciag.resize(n);
	rep(i,0,n) cin>>ciag[i];
	rep(i,0,m)
	{
		cin>>a;
		tab[a]=1;
	}
	rep(i,0,n) if (tab[ciag[i]]==1) cout <<ciag[i] <<" ";
	cout<< "\n";
}