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
typedef long double ld;

const int N = 4e5+10;

vector <int> kub[N];
set <int> duzo;
int main ()
{
	int n;
	scanf ("%d", &n);
	vector <int> tab(n);
	for (int &x: tab) scanf ("%d", &x);
	
	sort(tab.begin(), tab.end());
	vector <pair <int,int> > rob;
	pair <int,int> cur = mp(-1, 0);
	for (int x: tab)
	{
		if (x==cur.fi) cur.se++;
		else
		{
			if (cur.se>0) rob.pb(cur);
			cur = mp(x, 1);
		}
	}
	rob.pb(cur);
	for (auto &p: rob) swap(p.fi, p.se);
	sort(rob.begin(), rob.end());
	reverse(rob.begin(), rob.end());
	
	for (auto p: rob) debug ("%d %d\n", p.fi, p.se);
	
	int len = rob.size();
	int h = 1;
	int maks = 0;
	int lm, hm;
	int ptr = (int)rob.size()-1; //ostatni wyzszy niz minimum
	int suma = 0, sm = 0; //suma krotkich
	for (; len>0; len--)
	{
		for (;;)
		{
			while ( (ptr==-1 || rob[ptr].fi > h) && suma/(h+1) + ptr+1 >=len && h<len) h++;
			
			if (ptr >=0 && rob[ptr].fi==h) 
			{
				suma+=rob[ptr].fi;
				ptr--;
			}
			else break;
		}
		
		
		int d = h*len;
		if (maks < d)
		{
			maks = d;
			lm = len;
			hm = h;
			sm = suma;
		}
	}
	
	printf ("%d\n%d %d\n", maks, hm, lm);
	
	
	
	//robimy kubelki
	
	ptr = 0;
	rep(i,0,lm)
	{
		if (rob[ptr].fi >=hm)
		{
			duzo.insert(rob[ptr].se);
			rep(k,0,hm) kub[i].pb(rob[ptr].se);
			ptr++;
		}
		else
		{
			rep(k,0,hm)
			{
				if (rob[ptr].fi>0)
				{
					rob[ptr].fi--;
					kub[i].pb(rob[ptr].se);
				}
				else 
				{
					ptr++;
					k--;
				}
			}
		}
	}
	
	debug ("kubeliki\n");
	rep(i,0,lm) 
	{
		rep(j,0,hm) debug("%d ", kub[i][j]);
		debug ("\n");
	}
	
	vector <vector <int> > wynik(hm);
	
	rep(wys,0,hm)
	{
		wynik[wys].resize(lm);
		rep(i,0,lm) wynik[wys][i] = kub[(i+lm-wys)%lm][wys];
	}
	
	
	rep(i,0,hm)
	{
		set <int> wor;
		rep(j,0,lm) 
		{
			if (wor.count(wynik[i][j])==1)
			{
				if (duzo.count(wynik[i][j])==1) assert(0);
				assert(0);
			}
			wor.insert(wynik[i][j]);
		}
	}
	
	rep(j,0,lm) 
	{
		set <int> wor;
		rep(i,0,hm)
		{
			if (wor.count(wynik[i][j])==1)
			{
				if (duzo.count(wynik[i][j])==1) assert(0);
				assert(0);
			}
			wor.insert(wynik[i][j]);
		}
	}
	
	rep(i,0,hm)
	{
		for (int x: wynik[i]) printf ("%d ", x);
		printf ("\n");
	}
}