#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
int n, t, m, k;
vector <pair <long long, long long> > kni;
vector <long long> wyn, coins;
set <pair <long long, long long> > wor;
//suml
int main ()
{
	int a, b;	
	cin >>n >>k;
	kni.resize(n);
	wyn.resize(n);
	coins.resize(n);
	rep(i,0,n)
	{
		cin>>a;
		kni[i].fi=a;
		kni[i].se=i;
	}
	sort(kni.begin(), kni.end());
	long long suma=0;
	rep(i,0,n) 
	{
		cin>>coins[i];
		wyn[i]+=coins[i];
	}
	rep(i,0,n)
	{
		wyn[kni[i].se]+=suma;
		if (wor.size()<k) 
		{
			wor.insert(mp(coins[kni[i].se], kni[i].se));
			suma+=coins[kni[i].se];
		}
		else if (coins[kni[i].se]>wor.begin()->fi)
		{
			suma-=wor.begin()->fi;
			wor.erase(*wor.begin());
			wor.insert(mp(coins[kni[i].se], kni[i].se));
			suma+=coins[kni[i].se];
		}
	}
	rep(i,0,n) cout <<wyn[i] <<" ";
	cout <<"\n";
}