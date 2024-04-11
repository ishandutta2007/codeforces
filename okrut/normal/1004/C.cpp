#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
int n, m;
vector <int> tab, rob;
set <int> wor, wyk;
int main ()
{
	int a, b;
	cin>>n;
	tab.resize(n);
	rob.resize(1e5+1, 0);
	rep(i,0,n) cin>>tab[i];
	long long wyn=0;
	rep(i,0,n)
	{
		rob[tab[i]]=wor.size();
		wor.insert(tab[i]);
	}
	rep(i,0,1e5+1) wyn+=(long long)rob[i];
	cout <<wyn <<"\n";
	return 0;
}