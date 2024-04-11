#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = 1<<18;
const int N = 2e5+5;
const int M = 3e5+10;
const int Q = 5e5+100;

int Ojce[N], Time[N], Tree[T+T], P[N], Id[N], Pres[M], Range[N][2], Pos[N]; /* P[Id[i]] = i */

int maks (int l, int r)
{
	l+=T;
	r+=T;
	int ret = 0;
	while (l<r)
	{
		ret = max(ret, Tree[l]);
		ret = max(ret, Tree[r]);
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) ret = max(ret, Tree[l]);
	return ret;
}

void mark (int a, int x)
{
	a+=T;
	Tree[a] = x;
	while (a>1) {
		a/=2;
		Tree[a] = max(Tree[a*2], Tree[a*2+1]);
	}
}

int krol (int a)
{
	if (Ojce[a]==0) return a;
	return (Ojce[a] = krol(Ojce[a]));
}

bool unia (int &a, int &b)
{
	a = krol(a);
	b = krol(b);
	if (a==b) return false;
	Range[a][0] = min(Range[a][0], Range[b][0]);
	Range[a][1] = max(Range[a][1], Range[b][1]);
	Ojce[b] = a; 
	return true;
}

vector <int> graf[N]; 
int t;
void name(int a)
{
	Time[a] = t++;
	for (int s: graf[a]) name(s);
}

int main ()
{
	int n, m, q;
	scanf ("%d %d %d", &n, &m, &q);
	rep(i,1,n+1) scanf ("%d", &P[i]);
	
	rep(i,1,n+1) Id[P[i]] = i;
	rep(i,0,m) Pres[i] = 1;
	vector <pair <int, int> > edges(m), queries(q), ranges(q);
	for (auto &p: edges) scanf ("%d %d", &p.fi, &p.se);
	for (auto &p: queries) 
	{
		scanf ("%d %d", &p.fi, &p.se);
		if (p.fi==2)
		{
			Pres[--p.se] = 0;
		}
	}
	
	reverse(queries.begin(), queries.end());
	
	rep(i,0,m) if (Pres[i])
	{
		auto e = edges[i];
		
		if (unia(e.fi, e.se))
		{
			graf[e.fi].pb(e.se);
		}
	}
	
	for (auto p: queries) if (p.fi==2)
	{
		auto e = edges[p.se];
		if (unia(e.fi, e.se))
		{
			graf[e.fi].pb(e.se);
		}
	}
	
	rep(i,1,n+1) if (Ojce[i]==0) name(i);
	
	rep(i,1,n+1) 
	{
		Ojce[i] = 0;
		Range[i][0] = Range[i][1] = Time[i];
		mark(Time[i], P[i]);
		Pos[P[i]] = Time[i];
	}
	
	
	debug ("Got part 1: ");
	//rep(i,1,n+1) debug ("%d ", Time[i]);
	debug ("\n");
	
	int cnt = q;
	
	rep(i,0,m) if (Pres[i]) 
	{
		auto e = edges[i];
		unia(e.fi, e.se);
	}
	
	
	
	for (auto p: queries)
	{
		cnt--;
		
		if (p.fi==1)
		{
			int k = krol(p.se);
			
			debug ("at time of %d: range[%d] = %d %d\n", cnt, k, Range[k][0], Range[k][1]);
			
			ranges[cnt] = {Range[k][0], Range[k][1]};
		}
		else
		{
			auto e = edges[p.se];
			unia(e.fi, e.se);
		}
	}
	
	reverse(queries.begin(), queries.end());
	
	rep(i,0,q) if (queries[i].fi==1)
	{
		debug ("range is [%d %d]\n", ranges[i].fi, ranges[i].se);
		int r = maks(ranges[i].fi, ranges[i].se);
		if (r>0)
		{
			int pos = Pos[r];
			mark(pos, 0);
		}
		printf ("%d\n", r);
	}
	
}