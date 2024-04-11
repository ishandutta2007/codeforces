#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const char *M[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" }; 
char Buf[10];

const int N = 2e3+1;
int D[10], C[N];


int binary(const char *S)
{
	int ret = 0;
	rep(i,0,7) ret = ret*2 + (S[i]=='1'? 1 : 0);
	return ret;
}

/* jaka cyfre to zrobic */
int Best[N][N], Prv[N][N], Value[N][N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, k;
	scanf ("%d %d", &n, &k);
	rep(i,0,n)
	{
		scanf ("%s", Buf);
		C[i] = binary(Buf);
	}
	
	rep(i,0,10) 
	{
		D[i] = binary(M[i]);
	}
	
	rep(i,0,N) rep(j,0,N) Best[i][j] = -1; //nic sie nie da
	
	Best[0][0] = 0; //to jest jakas opcja
	
	rep(i,0,n)
	{
		rep(j,0,k+1) rep(d,0,10) if ( (D[d] & C[i])==C[i])
		{
			int add = __builtin_popcount(D[d] - C[i]);
			//debug ("%d %d %d: add %d\n", i, j, d, add);
			if (add>j) continue;
			if (Best[i][j-add]==-1) continue;
			int val = Value[i][j-add]*10 + d;
			if (val < Value[i+1][j]) continue;
			Value[i+1][j] = val;
			Prv[i+1][j] = j-add;
			Best[i+1][j] = d;
		}
		
		set <int> V;
		rep(j,0,k+1) if (Best[i+1][j]>=0)
		{
			V.insert(Value[i+1][j]);
		}
		map <int, int> Map;
		int x = 0;
		for (int v: V) Map[v] = x++;
		
		rep(j,0,k+1) if (Best[i+1][j]>=0) Value[i+1][j] = Map[Value[i+1][j]];
	}
	
	if (Best[n][k]==-1) printf ("-1\n");
	else
	{
		for (int i=n; i>0; i--)
		{
			C[i] = Best[i][k];
			k = Prv[i][k];
		}
		
		rep(i,1,n+1) printf ("%d", C[i]);
		printf ("\n");
	}
	
}