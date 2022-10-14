#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	vector <int> R(n), tab[3];
	for (int &r: R) scanf ("%d", &r);
	sort(R.begin(), R.end());
	
	
	pair <int, int> cnt = {0,0};
	
	priority_queue <pair <int, int> > kol;
	
	for (int r: R)
	{
		if (r==cnt.se) cnt.fi++;
		else
		{
			if (cnt.fi>0) kol.push(cnt);
			cnt.se = r;
			cnt.fi = 1;
		}
	}
	kol.push(cnt);
	
	
	
	
	pair <int, int> T[3];
	int res = 0;
	
	while (kol.size() >2)
	{
		rep(i,0,3)
		{
			T[i] = kol.top();
			kol.pop();
			
			tab[i].pb(T[i].se);
		}
		res++;
		rep(i,0,3) if ((--T[i].fi)>0)
		{
			kol.push(T[i]);
		}
	}
	
	printf ("%d\n", res);
	
	rep(i,0,res) 
	{
		vector <int> ball = {tab[0][i], tab[1][i], tab[2][i]};
		sort(ball.begin(), ball.end());
		printf ("%d %d %d\n", ball[2], ball[1], ball[0]);
	}
	
	
}