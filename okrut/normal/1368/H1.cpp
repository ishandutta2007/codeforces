#pragma GCC optimize "O3"
#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = 1<<17;
const ll INF = 1e16;
const int N = 1e5;


struct Ports {
	int Sum[T+T], S[T+T];
	int n;
	
	void init (int a, int lewy, int prawy, string &s)
	{
		if (lewy==prawy)
		{
			Sum[a] = (s[lewy]=='R')? 1 : 0;
		}
		else
		{
			init(a*2, lewy, mitte, s);
			init(a*2+1, mitte+1, prawy, s);
			Sum[a] = Sum[a*2] + Sum[a*2+1];
		}
	}
	
	void fill (string &s)
	{
		n = s.size();
		init(1,0,n-1, s);
	}
	
	ll count(int a)
	{
		if (a==1) return Sum[1];
		else return n - Sum[1];
	}
	
	void up(int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			S[a*2]^=S[a];
			S[a*2+1]^=S[a];
		}
		if (S[a]) Sum[a] = (prawy - lewy+1) - Sum[a];
		S[a] = 0;
	}
	
	void update (int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			S[a*2]^=S[a];
			S[a*2+1]^=S[a];
			up(a*2, lewy, mitte);
			up(a*2+1, mitte+1, prawy);
			S[a] = 0;
			Sum[a] = Sum[a*2] + Sum[a*2+1];
		}
		else up(a, lewy, prawy);
	}
	
	void modify(int left, int right, int a, int lewy, int prawy)
	{
		up(a, lewy, prawy);
		if (left<=lewy && right>=prawy) S[a]^=1;
		else
		{
			if (left<=mitte) modify(left, right, a*2, lewy, mitte);
			if (right>mitte) modify(left, right, a*2+1, mitte+1, prawy);
		}
		update(a, lewy, prawy);
	}
};

// Assuming vertical
struct Dp {
	ll Tree[4][T+T][4];
	int C[N][2], Border[2][2], S[T+T];
	int n;
	ll p; //cost of the cut
	
	void up (int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			S[a*2]^=S[a];
			S[a*2+1]^=S[a];
		}
		if (S[a])
		{
			ll Cpy[4][4];
			rep(i,0,4) rep(j,0,4) Cpy[i][j] = Tree[i][a][j];
			
			rep(i,0,4) rep(j,0,4) Tree[i][a][j] = Cpy[i^S[a]][j];
			
			S[a] = 0;
		}
	}
	
	void printTree(int a, int lewy, int prawy)
	{
		debug ("\n%d [%d %d] {%d} (", a, lewy, prawy, S[a]);
		rep(i,0,4) debug (" %lld", Tree[0][a][i]);
		debug (" )\n");
		
		if (lewy<prawy)
		{
			printTree(a*2, lewy, mitte);
			printTree(a*2+1, mitte+1, prawy);
		}
	}
	
	void print()
	{
		debug ("\n\nPrinting the DP:\n");
		debug ("Borders: (");
		rep(i,0,2) rep(j,0,2) debug ("%d ", Border[i][j]);
		debug (")\n");
		
		debug ("\nPrinting the tree:\n");
		printTree(1,0, n-1);
	}
	
	void merge (ll *L, ll *R, ll *Res)
	{
		if (false)
		{
			debug ("\n\nMerge: ");
			rep(i,0,4) debug ("%lld ", L[i]);
			debug (" vs ");
			rep(i,0,4) debug ("%lld ", R[i]);
			debug ("\n");
		}
		
		rep(s,0,4) Res[s] = INF;
		rep(s,0,4) rep(il,0,2) rep(ir,0,2)
		{
			int l = (s&1) + (il<<1);
			int r = ir + (s&2);
			
			ll curr = ll((((l>>1)^r)&1)) * p + L[l] + R[r];
			
			//debug ("from %d %d make %d (%d)\n", l, r, s, curr);
			
			Res[s] = min(Res[s], curr);
		}
	}
	
	void init (int a, int lewy, int prawy)
	{
		if (lewy==prawy)
		{
			rep(s,0,4)
			{
				rep(i,0,2) if (s&(1<<i)) C[lewy][i]^=1;
				
				Tree[s][a][1] = Tree[s][a][2] = INF;
				Tree[s][a][0] = C[lewy][0] + C[lewy][1];
				Tree[s][a][3] = 2 - C[lewy][0] - C[lewy][1];
				
				rep(i,0,2) if (s&(1<<i)) C[lewy][i]^=1;
			}
		}
		else
		{
			init(a*2, lewy, mitte);
			init(a*2+1, mitte+1, prawy);
			rep(s,0,4) merge(Tree[s][a*2], Tree[s][a*2+1], Tree[s][a]);
		}
	}
	
	void fill (int pval, string &U, string &D)
	{	
		p = pval;
		n = U.size();
		rep(i,0,n)
		{
			C[i][0] = (U[i]=='R');
			C[i][1] = (D[i]=='R');
		}
		
		init(1, 0, n-1);
	}
	
	
	
	void update (int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			S[a*2]^=S[a];
			S[a*2+1]^=S[a];
			up(a*2, lewy, mitte);
			up(a*2+1, mitte+1, prawy);
			
			S[a] = 0;
			rep(s,0,4) merge(Tree[s][a*2], Tree[s][a*2+1], Tree[s][a]);
		}
		else up(a, lewy, prawy);
	}
	
	void modify (int left, int right, int x, int a, int lewy, int prawy)
	{
		if (S[a]) up(a, lewy, prawy);
		if (left<=lewy && right>=prawy)
		{
			S[a]^=x;
		}
		else
		{
			if (left<=mitte) modify(left, right, x, a*2, lewy, mitte);
			if (right>mitte) modify(left, right, x, a*2+1, mitte+1, prawy);
		}
		update(a, lewy, prawy);
	}
	
	ll cost ()
	{
		ll ret = INF;
		rep(k,0,4)
		{
			ll curr = Tree[0][1][k];
			
			rep(s,0,2)
			{
				int wrong;
				if (k&(1<<s)) wrong = 0;
				else wrong = 1;
				
				curr += ll(Border[s][wrong]);
			}
			ret = min(curr, ret);
		}
		return ret;
	}
};

Dp H, V;
Ports L, R, U, D;

void borders ()
{
	rep(c,0,2)
	{
		V.Border[0][c] = L.count(c);
		V.Border[1][c] = R.count(c);
		H.Border[0][c] = U.count(c);
		H.Border[1][c] = D.count(c);
	}
}


void printState()
{
	//debug ("\nV tree:\n");
	//V.print();
	
	debug ("\n\nH tree:\n");
	H.print();
}

int main ()
{
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin>>n >>m >>q;
	
	string left, right, up, down;
	cin>>left >>right >>up >>down;
	
	
	L.fill(left);
	R.fill(right);
	U.fill(up);
	D.fill(down);
	
	V.fill(n, up, down);
	H.fill(m, left, right);
	
	borders();
	
	ll res = min(H.cost(), V.cost());
	cout<<res <<"\n";
	rep(i,0,q)
	{
		char type;
		int l, r;
		cin>>type >>l >>r;
		l--; r--;
		
		if (type=='L') 
		{
			L.modify(l, r, 1, 0, n-1);
			
			H.modify(l, r, 1, 1, 0, n-1);
		}
		if (type=='R')
		{
			R.modify(l, r, 1, 0, n-1);
			
			H.modify(l, r, 2, 1, 0, n-1);
		}
		if (type=='U')
		{
			U.modify(l, r, 1, 0, m-1);
			
			V.modify(l, r, 1, 1, 0, m-1);
		}
		if (type=='D')
		{
			D.modify(l, r, 1, 0, m-1);
			
			V.modify(l, r, 2, 1, 0, m-1);
		}
		
		
		borders();
		
		
		res = min(H.cost(), V.cost());
		cout<<res <<"\n";
	}
	
}