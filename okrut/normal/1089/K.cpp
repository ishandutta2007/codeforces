#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //

typedef long long ll;
typedef pair<int, int> pii;
const int p=1005;
const int n=1005;
struct dzial 
{
	vector <ll> tab; //czas trwania wizyty o danym poczatku
	ll del, rel;
	ll  wolne; //dalay, relative delay and free
	ll m;
	ll sum;
	void policz (ll delay) //delay z poprzedniego 
	{
		sum=0;
		ll t=0; //curr time
		rep(i,0,m)
		{
			sum+=tab[i];
			if (t<=i) t=i+tab[i]; //czas trwania
			else t+=tab[i];
		}
		ll tr=delay; //obsuwa
		wolne=0;
		rep(i,0,m)
		{
			if (tr<=i) tr=i+tab[i];
			else tr+=tab[i];
			if (tr<=i) wolne++;
		}
		del=max(0LL,t-m);
		rel=max(0LL, tr-m);
		rel-=del;
	}
	ll when (int t, ll delay)
	{
		ll tr=delay;
		rep(i,0,m)
		{
			if (tr<=i) tr=i+tab[i];
			else tr+=tab[i];
			if (i==t) return tr-(ll)t;
		}
		return 0; //cos nie dziala
	}
};
vector <dzial> tab;
vector <int> czasy;
void init ()
{
	tab.resize(n);
	rep(i,0,n)
	{
		tab[i].tab.resize(p,0);
		tab[i].sum=0;
		tab[i].wolne=p;	
		tab[i].rel=0;
		tab[i].del=0;
		tab[i].m=p;
	}
}
int main()
{
	init();
	int q;
	scanf ("%d", &q);
	char type;
	int t, g, d;
	czasy.resize(q,0);
	ll obsuwa;
	ll delta;
	ll res;
	ll przed; //previous delay
	rep(qwa,0,q)
	{
		scanf (" %c %d", &type, &t);
		czasy[qwa]=t-1;
		if (type=='+')
		{
			t--;
			g=t/p;
			scanf ("%d", &d);
			if (t>1e6) continue;
			obsuwa=tab[g].del+tab[g].rel;
			tab[g].tab[t%p]=d;
			debug ("dodajemy %d: w %d %d\n", d, g, t%p);
			if (g==0) tab[g].policz(0);
			else tab[g].policz(tab[g-1].del+tab[g-1].rel);
			delta=tab[g].del+tab[g].rel-obsuwa; //o tyle wzroslo
			g++;
			while (g<n) //liczba pierwiastkow
			{
				if (tab[g].wolne>=delta) 
				{
					tab[g].wolne-=delta;
					delta=0;
				}
				else
				{
					delta-=tab[g].wolne;
					tab[g].wolne=0;
				}
				tab[g].rel+=delta;
				g++;
			}
		}
		if (type=='-')
		{
			t--;
			t=czasy[t];
			g=t/p;
			obsuwa=tab[g].del+tab[g].rel;
			tab[g].tab[t%p]=0;
			if (g==0) tab[g].policz(0);
			else tab[g].policz(tab[g-1].del+tab[g-1].rel);
			delta=obsuwa-tab[g].del-tab[g].rel; //o ile przyspieszamy
			przed=tab[g].del+tab[g].rel;
			g++;
			
			//przy odejmowaniu moga sie zmienic obsuwy i liczba wolnych miejsc
			
			while (g<n)
			{
				if (tab[g].rel>=delta)
				{
					tab[g].rel-=delta; //obsuwa sie nie zmienia
				}
				else
				{
					delta=tab[g].rel;
					tab[g].rel=0; //tutaj wyczyscilem
				}
				tab[g].wolne=ll(p)+tab[g].rel+tab[g].del-przed-tab[g].sum; //my own delay
				przed=tab[g].del+tab[g].rel;
				g++;
			}
		}
		if (type=='?')
		{
			t--;
			g=t/p;
			if (g==0) res=tab[g].when (t%p, 0);
			else res=tab[g].when(t%p, tab[g-1].del+tab[g-1].rel);
			printf ("%lld\n", res);
			//przeszukaj kiedy wejdzie
		}
	}
	return 0;
}