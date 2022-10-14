#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
int tab[27];
bool eqi (string &a, string &b)
{
	rep(i,0,27) tab[i]=0;
	rep(i,0,(int)a.size()) tab[a[i]-'a']++;
	rep(i,0,(int)b.size()) tab[b[i]-'a']--;
	rep(i,0,27) if (tab[i]!=0) return false;
	if (a==b) return true;
	else if (a.size()%2==0)
	{
		string c, d, e, f;
		rep(i,0,(int)a.size()/2)
		{
			c.pb(a[i]);
			d.pb(a[i+a.size()/2]);
			e.pb(b[i]);
			f.pb(b[i+b.size()/2]);
		}
		if (rand()%2==0)
		{
			if (rand()%2==0) 
			{
				if (eqi(c, e)) if (eqi(d,f)) return true;
			}
			else 
			{
				if (eqi(d,f)) if (eqi(c, e)) return true;
			}
			
			if (rand()%2==0) 
			{
				if (eqi(c, f)) if (eqi(d,e)) return true;
			}
			else 
			{
				if (eqi(d,e)) if (eqi(c, f)) return true;
			}
		}	
		else
		{
			if (rand()%2==0) 
			{
				if (eqi(c, f)) if (eqi(d,e)) return true;
			}
			else 
			{
				if (eqi(d,e)) if (eqi(c, f)) return true;
			}
			
			if (rand()%2==0) 
			{
				if (eqi(c, e)) if (eqi(d,f)) return true;
			}
			else 
			{
				if (eqi(d,f)) if (eqi(c, e)) return true;
			}
		}
	}	
	return false;
}
int main ()
{
	srand(321239023);
	string a, b;
	cin>>a >>b;
	if (eqi(a,b)) printf ("YES\n");
	else printf ("NO\n");
}