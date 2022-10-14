#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
string tekst;
vector <int> tab;
int main ()
{
	int n;
	int k='Z'-'A'+2;
	tab.resize(k*k, 0);
	ios_base::sync_with_stdio(false);
	cin>>n;
	cin>>tekst;
	rep(i,1,n) tab[(tekst[i-1]-'A')*k+tekst[i]-'A']++;
	pair <int, int> maks=mp(0,0);
	rep(i,0,(int)tab.size()) if (tab[i]>maks.fi) maks=mp(tab[i], i);
	printf ("%c%c\n", maks.se/k+'A', maks.se%k+'A');
}