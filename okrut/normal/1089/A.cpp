#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf

typedef long long ll;
typedef pair<int, int> pii;

pair<int, int> wyniki[5];


bool proba(int a, int b, int ile)
{
	for(int i = 0; i < 5; i++)
		wyniki[i].fi = wyniki[i].se = 0;
	if(ile == 0)
	{
		wyniki[0].fi = 25;
		wyniki[1].fi = 25;
		wyniki[2].fi = 25;
		a -= 75;
		
		if(a < 0)
			return false;
		
		wyniki[0].se = min(23, b);
		b -= wyniki[0].se;

		if(a > 0)
		{
			if(a > b || wyniki[0].se != 23) return false;
			
			wyniki[0].fi += a;
			wyniki[0].se += a;
			b -= a;
		}
		wyniki[1].se = min(23, b);
		b -= wyniki[1].se;
		wyniki[2].se = min(23, b);
		b -= wyniki[2].se;
		
		if(b > 0)
			return false;
		return true;
	}
	else if(ile == 1)
	{
		wyniki[0].fi = 25;
		wyniki[1].fi = 25;
		wyniki[2].se = 25;
		wyniki[3].fi = 25;
		a -= 75;
		b -= 25;
		
		if(a < 0)
			return false;
		if(b < 0)
			return false;
			
		if(b - 69 > a - 23)
		{
			wyniki[0].se = min(23, b);
			b -= wyniki[0].se;
			wyniki[1].se = min(23, b);
			b -= wyniki[1].se;
			wyniki[3].se = min(23, b);
			b -= wyniki[3].se;
			
			if(b > 0)
			{
				if(b > a) return false;
				wyniki[0].fi += b;
				wyniki[0].se += b;
				a -= b;
			}
			
			wyniki[2].fi = min(23, a);
			a -= wyniki[2].fi;
			
			if(a > 0)
				return false;
		}
		else
		{
			wyniki[2].fi = min(23, a);
			a -= wyniki[2].fi;
			
			if(a > 0)
			{
				if(a > b) return false;
				wyniki[2].fi += a;
				wyniki[2].se += a;
				b -= a;
			}
			
			wyniki[0].se = min(23, b);
			b -= wyniki[0].se;
			wyniki[1].se = min(23, b);
			b -= wyniki[1].se;
			wyniki[3].se = min(23, b);
			b -= wyniki[3].se;
			
			if(b > 0)
				return false;
		}
		
		return true;
	}
	else
	{
		wyniki[0].fi = 25;
		wyniki[1].fi = 25;
		wyniki[2].se = 25;
		wyniki[3].se = 25;
		wyniki[4].fi = 15;
		
		a -= 65;
		b -= 50;
		
		if(a < 0)
			return false;
		if(b < 0)
			return false;
			
		if(b - 59 > a - 46)
		{
			wyniki[0].se = min(23, b);
			b -= wyniki[0].se;
			wyniki[1].se = min(23, b);
			b -= wyniki[1].se;
			wyniki[4].se = min(13, b);
			b -= wyniki[4].se;
			
			if(b > 0)
			{
				if(b > a) return false;
				wyniki[0].fi += b;
				wyniki[0].se += b;
				a -= b;
			}
			
			wyniki[2].fi = min(23, a);
			a -= wyniki[2].fi;
			wyniki[3].fi = min(23, a);
			a -= wyniki[3].fi;
			
			if(a > 0)
				return false;
		}
		else
		{
			wyniki[2].fi = min(23, a);
			a -= wyniki[2].fi;
			wyniki[3].fi = min(23, a);
			a -= wyniki[3].fi;
			
			if(a > 0)
			{
				if(a > b) return false;
				wyniki[2].fi += a;
				wyniki[2].se += a;
				b -= a;
			}
			
			wyniki[0].se = min(23, b);
			b -= wyniki[0].se;
			wyniki[1].se = min(23, b);
			b -= wyniki[1].se;
			wyniki[4].se = min(13, b);
			b -= wyniki[4].se;
			
			if(b > 0)
				return false;
		}
		
		return true;
	}
}


void solve()
{
	int a, b;
	cin >> a >> b;
	
	if(proba(a, b, 0))
	{
		cout << "3:0" << "\n";
		for(int i = 0; i < 3; i++)
			cout << wyniki[i].fi << ":" << wyniki[i].se << " ";
		return;
	}
	if(proba(a, b, 1))
	{
		cout << "3:1" << "\n";
		for(int i = 0; i < 4; i++)
			cout << wyniki[i].fi << ":" << wyniki[i].se << " ";
		return;
	}
	if(proba(a, b, 2))
	{
		cout << "3:2" << "\n";
		for(int i = 0; i < 5; i++)
			cout << wyniki[i].fi << ":" << wyniki[i].se << " ";
		return;
	}
	if(proba(b, a, 2))
	{
		cout << "2:3" << "\n";
		for(int i = 0; i < 5; i++)
			cout << wyniki[i].se << ":" << wyniki[i].fi << " ";
		return;
	}
	if(proba(b, a, 1))
	{
		cout << "1:3" << "\n";
		for(int i = 0; i < 4; i++)
			cout << wyniki[i].se << ":" << wyniki[i].fi << " ";
		return;
	}
	if(proba(b, a, 0))
	{
		cout << "0:3" << "\n";
		for(int i = 0; i < 3; i++)
			cout << wyniki[i].se << ":" << wyniki[i].fi << " ";
		return;
	}
	cout << "Impossible";
	
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << "\n";	
	}
	return 0;
}