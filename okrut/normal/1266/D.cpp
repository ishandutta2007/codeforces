#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf  
using namespace std;
typedef long long ll;
typedef long double ld;


const int N = 1e5+100;
map <int, ll> in[N], out[N];

void trans (int a, int b, int c, ll d) //a -> b-> c : d
{
	out[a][b] -= d;
	out[a][c] += d;
	
	in[b][a]-=d;
	out[b][c]-=d;
	
	in[c][a] += d; 
	in[c][b] -= d;
}
int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	vector <pair <int, int> > tab(n, mp(0,0));
	rep(i,0,m)
	{
		int a, b;
		ll c;
		scanf ("%d %d %lld", &a, &b, &c);
		out[a][b]+=c;
		in[b][a]+=c;
		tab[a-1].fi++;
		tab[b-1].fi++;
	}
	rep(i,0,n) tab[i].se = i+1;
	sort(tab.begin(), tab.end());
	
	int mp = 0;
	for (auto q: tab)
	{
		int i = q.se;
		ll sum = 0LL, c1 = 0, c2 = 0;
		out[i][i] = 0LL;
		in[i][i] = 0LL;
		
		vector <pair <int, ll> > myin, myout;
		for (auto p: out[i]) 
		{
			myout.pb(p);
			sum+=p.se;
			c1+=p.se;
		}
		for (auto p: in[i]) 
		{
			myin.pb(p);
			sum-=p.se;
			c2+=p.se;
		}
		
		ll c = min(c1, c2);
		int wi = 0, wo = 0;
		while (c>0LL)
		{
			while (myout[wo].se==0LL) wo++;
			while (myin[wi].se==0LL) wi++;
			ll d = min(c, min(myout[wo].se, myin[wi].se));
			
			trans(myin[wi].fi, i, myout[wo].fi, d);
			
			myout[wo].se-=d;
			myin[wi].se-=d;
			c-=d;
			//te przepinam, reszta zostaje
		}
	}
	
	rep(i,1,n+1) out[i][i] = 0LL;
	
	mp = 0;
	rep(i,1,n+1) for (auto p: out[i]) if (p.se > 0LL) mp++;
	printf ("%d\n", mp);
	rep(i,1,n+1)
	{
		for (auto p: out[i]) if (p.se > 0LL) printf ("%d %d %lld\n", i, p.fi, p.se);
	}
}