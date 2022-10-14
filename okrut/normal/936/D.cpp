#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int M = 2e6+5;
vector <int> poswek, turn, pos;
vector <pair <int, int> > obs; //obstacles
int dp[M][2], wall[M][2];
int n, m1, m2, t;
vector <pair <int, int> > shot;
int licz=0;
void track (int a, int b, int c = n-1) //c - najpozniejsze pole, gdzie moge strzelac
{
	if ((licz++) > M)
	{
		printf ("too long track %d %d\n", a, b);
		assert(0);
	}
	if (a==0) 
	{
		if (b==1) turn.pb(0);
		return; //jestem na koncu i jest ok
	}
	c = min(c, poswek[a]-1);
	
	debug ("track %d (%d) %d %d\n", a, poswek[a], b, c);
	
	if (wall[a][b]==1) //musialem strzelac
	{	
		debug ("have to shoot\n");
		shot.pb(mp(c,b));
		c-=t;
		track(a-1, b, c);
	}
	else
	{
		if (dp[a-1][b]+poswek[a] - poswek[a-1] ==dp[a][b]) //bylem na wprost
		{
			debug ("wprost\n");
			track(a-1, b, c);
		}
		else
		{
			turn.pb(poswek[a]);
			assert(dp[a][b] == min(dp[a][b^1], t));
			track(a, b^1, c);
		}
	}
}
int main ()
{
	memset(wall, 0, sizeof wall);
	scanf ("%d %d %d %d", &n, &m1, &m2, &t);
	pos.pb(n);
	pos.pb(0);
	int x, q;
	rep(i,0,m1)
	{
		scanf ("%d", &x);
		obs.pb(mp(x,0));
		pos.pb(x);
		pos.pb(x+1);
	}
	rep(i,0,m2)
	{
		scanf ("%d", &x);
		obs.pb(mp(x, 1));
		pos.pb(x);
		pos.pb(x+1);
	}
	sort(pos.begin(), pos.end());
	
	if ((int)pos.size()>0) poswek.pb(pos[0]);
	rep(i,1,(int)pos.size()) if (pos[i]>pos[i-1]) poswek.pb(pos[i]);
	pos.clear();
	rep(i,1,(int)poswek.size()) pos.pb(poswek[i]);
	
	
	
	sort(obs.begin(), obs.end());
	x=0;
	q=0;
	for (int p: pos)
	{
		q++;
		while (x < (int)obs.size() && obs[x].fi==p)
		{
			wall[q][obs[x].se]=1; 
			x++;
		}
	}
	q=0;
	int old = 0;
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int p: pos)
	{
		q++;
		debug ("x: %d (ruch o %d)\n", p, p - old);
		rep(i,0,2) 
		{
			if (dp[q-1][i]<0) dp[q][i] = -1;
			else
			{
				if (wall[q][i]==1) dp[q][i] = dp[q-1][i] + p - old - t;
				else dp[q][i] = dp[q-1][i] + p - old;
			}
		}
		int star[2];
		star[0] = dp[q][0];
		star[1] = dp[q][1];
		rep(i,0,2) 
		{
			if (wall[q][i]==0) dp[q][i] = max(dp[q][i], min(star[i^1], t));
			if (dp[q][i]<=0) dp[q][i]=-1;
		}
		old = p;
	}
	
	obs.clear();
	
	debug ("test\n");
	rep(i,0,q+1) 
	{
		debug ("%d %d (%d %d)\n", dp[i][0], dp[i][1], wall[i][0], wall[i][1]);
	}
	
	if (dp[q][0]>=0)
	{
		printf ("Yes\n");
		track(q, 0);
	}
	else if (dp[q][1]>=0)
	{
		printf ("Yes\n");
		track(q, 1);
	}
	else
	{
		printf ("No\n");
		return 0;
	}
	
	reverse(turn.begin(), turn.end());
	reverse(shot.begin(), shot.end());
	
	printf ("%d\n", (int)turn.size());
	for (int s: turn) printf ("%d ", s);
	printf ("\n%d\n", (int)shot.size());
	for (pair <int, int> p: shot) printf ("%d %d\n", p.fi, p.se+1);
	
}