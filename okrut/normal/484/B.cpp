#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
vector <int> ile, tab; //ile do najblizszej liczby
int main ()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	tab.resize(n);
	ile.resize(2e6+5, 1e9);
	int maks=0;
	rep(i,0,n) 
	{
		cin>>tab[i];
		ile[tab[i]]=0;
		maks=max(maks, tab[i]);
	}
	rep(i,1,maks*2+5) ile[i]=min(ile[i], ile[i-1]+1);
	sort(tab.begin(), tab.end());
	int best=0;
	tab.pb(-1);
	for (int i=n-1; i>=0; i--) if (tab[i]>best+1) if (tab[i]!=tab[i+1])
	{
		int y=tab[i]-1+tab[i]; //sytuacja poczatkowa
		while (y-tab[i]<=maks)
		{
			best=max(best, tab[i]-1-ile[y]);
			y+=tab[i];
		}
	}
	cout<<best <<"\n";
}