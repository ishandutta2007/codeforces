#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e5+10;
int A[N], F[N];
const int T = 1<<19;
int Tree[T+T], Up[T+T], Maks[T+T], Rem[N], Sum[T+T], Res[N]; //removed at moment

void up (int a, int lewy, int prawy)
{
	if (lewy < prawy)
	{
		Up[a*2] += Up[a];
		Up[a*2+1] += Up[a];
	}
	Tree[a]+=Up[a];
	Up[a] = 0;
}

void update (int a, int lewy, int prawy)
{
	up(a, lewy, prawy);
	if (lewy < prawy)
	{
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		Tree[a] = min(Tree[a*2], Tree[a*2+1]);
	}
}
void erase (int pos, int a=1, int lewy=0, int prawy=T-1)
{
	up(a, lewy, prawy);
	if (lewy==prawy) Tree[a] = N+N;
	else
	{
		if (pos<=mitte) erase(pos, a*2, lewy, mitte);
		else erase(pos, a*2+1, mitte+1, prawy);
		update(a, lewy, prawy);
	}
}

void mark (int l, int a=1, int lewy=0, int prawy=T-1)
{
	up(a, lewy, prawy);
	if (lewy>=l) Up[a] = -1;
	else
	{
		if (mitte >= l) mark(l, a*2, lewy, mitte);
		mark(l, a*2+1, mitte+1, prawy);
		update(a, lewy, prawy);
	}
}
/* returns the rightmost minimum */
int read (int a=1, int lewy=0, int prawy=T-1)
{
	up(a, lewy, prawy);
	
	if (lewy==prawy) return lewy;
	else
	{
		update(a, lewy, prawy);
		if (Tree[a*2+1]==Tree[a]) return read(a*2+1, mitte+1, prawy);
		else return read(a*2, lewy, mitte);
	}
}

int maks (int l, int r)
{
	int ret = 0;
	l+=T;
	r+=T;
	while (l<r)
	{
		ret = max(ret, Maks[l]);
		ret = max(ret, Maks[r]);
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) ret = max(ret, Maks[l]);
	return ret;
}

void ustaw (int a, int x)
{
	a+=T;
	for (Maks[a]=x; a>0; a/=2) Maks[a] = max(Maks[a], x); 
}

int sum (int l, int r)
{
	int ret = 0;
	l+=T;
	r+=T;
	while (l<r)
	{
		if (l%2==1) ret+=Sum[l];
		if (r%2==0) ret+=Sum[r];
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) ret += Sum[l];
	return ret;
}
void add (int a)
{
	for (a+=T; a>0; a/=2) Sum[a]++;
}



int main ()
{
	int n, q;
	scanf ("%d %d", &n, &q);
	rep(i,0,n) scanf ("%d", &A[i]);
	
	/* calculate F */
	
	rep(i,T,T+T) Tree[i] = N+N;
	
	rep(i,0,n) 
	{
		Tree[T+i] = (i+1 >= A[i] ? i+1 - A[i] : N+N);
		debug ("%d: %d\n", i, Tree[T+i]);
	}
	
	for (int i=T-1; i>1; i--) Tree[i] = min(Tree[i*2], Tree[i*2+1]);
	
	rep(i,0,T+T) Maks[i] = 0;
	rep(i,0,n) F[i] = -1;
	
	for (int t = 1; Tree[1]==0; t++)
	{
		int v = read();
		Rem[t] = v;
		
		
		mark(v);
		erase(v);
		
		int latest = maks(0,v);
		if (latest==0) F[v] = v;
		else F[v] = F[Rem[latest]];
		
		ustaw(v, t);
	}
	
	assert(Tree[1]>0);
	
	//rep(i,0,n) debug ("%d (%d) \n", A[i], F[i]);
	debug ("\n");
	
	vector <pair <pair <int, int>, int > > Q(q);
	int cnt = 0;
	for (auto &p: Q) 
	{
		scanf ("%d %d", &p.fi.fi, &p.fi.se);
		p.fi.se = n -1 - p.fi.se;
		swap(p.fi.fi, p.fi.se);
		p.se = cnt++;
	}
	
	sort(Q.begin(), Q.end());
	auto query = Q.begin();
	rep(r,0,n)
	{
		if (F[r]>=0) add(F[r]);
		
		while (query!=Q.end() and query->fi.fi==r)
		{
			debug ("do %d %d (%d)\n", query->fi.se, query->fi.fi, query->se);
			
			Res[query->se] = sum(query->fi.se, query->fi.fi);
			query++;
		}
	}
	
	rep(i,0,q) printf ("%d\n", Res[i]);
	
}