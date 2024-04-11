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

const int N = 200001;

int tab[N], F[N], L[N], kub[N], ile[N];
set <int> S[N];
vector <pair <int, int> > pary;

int main ()
{
	int n, q;
	scanf ("%d %d", &n, &q);
	rep(i,0,n) scanf ("%d", &tab[i]);
	
	rep(i,0,N) F[i] = L[i] = -1;
	
	rep(i,0,n)
	{
		ile[tab[i]]++;
		if (F[tab[i]]==-1) F[tab[i]]=i;
		L[tab[i]] = i;
	}
	
	int k = 0;
	
	rep(i,0,N) if (L[i]>=0) pary.pb(mp(F[i], L[i]));
	sort(pary.begin(), pary.end());
	int end = -1;
	for (auto p: pary)
	{
		if (p.fi>end) k++;
		int nend = p.se;
		rep(i,end+1,nend+1) kub[i] = k;
		end = max(end, nend);
		
	}
	
	rep(i,0,n)
	{
		S[kub[i]].insert(tab[i]);
	}
	int res = 0;
	rep(i,1,k+1)
	{
		vector <int> rob;
		for (int s: S[i]) rob.pb(ile[s]);
		sort(rob.begin(), rob.end());
		rep(i,0,(int)rob.size()-1) res+=rob[i];
	}
	printf ("%d\n", res);
}