#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
vector <int> tab;

int n, m, k;
int main ()
{
	int a, b;
	cin>>n;
	tab.resize(n);
	rep(i,0,n) cin>>tab[i];
	sort(tab.begin(), tab.end());
	m=accumulate(tab.begin(), tab.end(), 0);
	k=n*4+n/2+n%2;
	a=0;
	while (m<k)
	{
		m+=5-tab[a];
		a++;
	}
	printf ("%d\n", a);
}