#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;

int main ()
{
	vector <int> tab(3,0);
	rep(i,0,3) cin>>tab[i];
	sort(tab.begin(), tab.end());
	cout<<max(0,tab[2]-tab[1]-tab[0]+1) <<"\n";
}