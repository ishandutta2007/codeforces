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

const int N = 2e5+10;
const int L = 19;
const int T = 1<<L;
int Up[L][N], Low[L][N], Depth[N], Tree[T+T], Head[N], Pod[N], In[N], Out[N];
int QBus[N], Res[N], t;
vector <int> graf[N], Bus[N];

int up (int a, int u, int tab[L][N])
{
	for (int i=0; i<L; i++) if (u & (1<<i)) a = tab[i][a];
	return a;
}

int lca (int a, int b)
{
	if (Depth[a] < Depth[b]) swap(a,b);
	a = up(a, Depth[a] - Depth[b], Up);
	if (a==b) return a;
	for (int i=L-1; i>=0; i--) if (Up[i][a] != Up[i][b])
	{
		a = Up[i][a];
		b = Up[i][b];
	}
	return Up[0][a];
}

void dfs0 (int a)
{
	Pod[a] = 1;
	for (int s: graf[a])
	{	
		Depth[s] = Depth[a]+1;
		dfs0(s);
		Pod[a] += Pod[s];
	}
}
void dfs1 (int a, int c)
{
	In[a] = t++;
	Head[a] = c;
	for (int s: graf[a]) if (Pod[s]*2 >= Pod[a]) dfs1(s, c);
	for (int s: graf[a]) if (Pod[s]*2 < Pod[a]) dfs1(s, s);
	Out[a] = t; //after them all
}

void mark (int l, int r, int x)
{
	l+=T;
	r+=T;
	while (l<r)
	{
		if (l%2==1) Tree[l] = min(Tree[l], x);
		if (r%2==0) Tree[r] = min(Tree[r], x);
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) Tree[l] = min(Tree[l], x);
}
int mini (int a)
{
	a+=T;
	int ret = N;
	while (a>0)
	{
		ret = min(ret, Tree[a]);
		a/=2;
	}
	return ret;
}
void add (int a)
{
	a+=T;
	while (a>0)
	{
		Tree[a]++;
		a/=2;
	}
}
int sum (int l, int r)
{
	l+=T;
	r+=T;
	int ret = 0;
	while (l<r)
	{
		if (l%2==1) ret += Tree[l];
		if (r%2==0) ret += Tree[r];
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) ret += Tree[l];
	return ret;
}

void markPath (int a, int u, int x)
{
	for (;;) {
		int h = Head[a];
		if (In[a] - In[h] +1 >= u)
		{
			mark(In[a] - u+1, In[a], x);
			break;
		}
		mark(In[h], In[a], x);
		u -= In[a] - In[h] +1;
		a = Up[0][h];
	}
}
int calcL (int a, int h)
{
	int l = 0, r = N;
	while (l<r)
	{
		int mid = (l+r)/2;
		int c = up(a, mid, Low);
		if (Depth[c] > h) l = mid+1;
		else r = mid;
	}
	return r;
}

vector <pair <int, pair <int, int> > > Q; //time, whoose sum, id
vector <pair <int, pair <int, int> > >::iterator it;

void process(int time)
{
	while (it!=Q.end() && it->fi==time)
	{
		auto [b, nr] = it->se;
		int s = sum(In[b], Out[b]-1);
		
		if (QBus[nr]==-1) QBus[nr] = s;
		else QBus[nr] = s - QBus[nr];
		
		debug ("process %d %d %d: %d\n", it->fi, it->se.fi, it->se.se, QBus[it->se.se]);
		it++;
	}
}
void dfs2 (int a)
{
	process(In[a]);
	debug ("jestem w %d\n", a);
	for (int b: Bus[a]) 
	{
		debug ("++T[%d]\n", b);
		add(In[b]);
	}
	
	for (int s: graf[a]) if (Pod[s]*2 >= Pod[a]) dfs2(s);
	for (int s: graf[a]) if (Pod[s]*2 < Pod[a]) dfs2(s);
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	Up[0][1] = 1;
	rep(i,2,n+1)
	{
		int p;
		scanf ("%d", &p);
		graf[p].pb(i);
		Up[0][i] = p;
	}
	dfs0(1);
	dfs1(1,1);
	
	rep(l,0,L-1) rep(v,1,n+1) Up[l+1][v] = Up[l][Up[l][v]];
	
	rep(i,0,T+T) Tree[i] = N;
	
	debug ("\nphase 1\n");
	
	int m;
	scanf ("%d", &m);
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		int c = lca(a,b);
		markPath(a, Depth[a] - Depth[c]+1, Depth[c]);
		markPath(b, Depth[b] - Depth[c]+1, Depth[c]);
		Bus[a].pb(b);
		Bus[b].pb(a);
	}
	
	debug ("Low table: ");
	
	rep(v,1,n+1)
	{
		int d = mini(In[v]);
		
		if (d==N) Low[0][v] = v;
		else Low[0][v] = up(v, Depth[v] - d, Up);
		
		debug ("%d ", Low[0][v], d);
	}
	debug ("\n");
	
	rep(l,0,L-1) rep(v,1,n+1) Low[l+1][v] = Low[l][Low[l][v]];
	
	
	rep(i,0,T+T) Tree[i] = 0;
	
	debug ("\nphase 2\n");
	
	int q;
	scanf ("%d", &q);
	rep(i,0,q)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		int c = lca(a,b);
		int la = calcL(a, Depth[c]);
		int lb = calcL(b, Depth[c]);
		
		debug ("trasa %d %d %d (%d %d)\n", a, b, c, la, lb);
		
		Res[i] = la+lb;
		
		if (Res[i] >= N) continue;
		
		if (la>0 && lb>0)
		{
			int ga = up(a, la-1, Low);
			int gb = up(b, lb-1, Low);
			
			debug ("lacz (%d %d) ?\n", ga, gb);
			
			QBus[i] = -1;
			Q.pb( {In[ga], {gb, i} } );
			Q.pb( {Out[ga], {gb, i}} );
		}
	}
	
	
	debug ("\nphase 3\n");
	
	sort(Q.begin(), Q.end());
	it = Q.begin();
	
	
	dfs2(1);
	process(t);
	
	rep(i,0,q) 
	{
		if (QBus[i]>0) 
		{
			debug ("%d: lacz\n", i);
			Res[i]--;
		}
		
		if (Res[i]>=N) Res[i] = -1;
	}
	
	rep(i,0,q) printf ("%d\n", Res[i]);
}