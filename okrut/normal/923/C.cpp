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

const int N = 3e5+100;

int Cnt[N*30];
pair <int, int> Go[N*30];

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <int> A(n), P(n);
	for (auto &a: A) scanf ("%d", &a);
	for (auto &p: P) scanf ("%d", &p);
	
	int q = 1;
	for (auto p: P)
	{
		int v = 0;
		for (int i=29; i>=0; i--)
		{
			if (p & (1<<i))
			{
				if (Go[v].fi==0) Go[v].fi = q++;
				v = Go[v].fi;
			}
			else
			{
				if (Go[v].se==0) Go[v].se = q++;
				v = Go[v].se;
			}
			Cnt[v]++;
		}
	}
	
	for (auto a: A)
	{
		int v = 0;
		int p = a;
		for (int i=29; i>=0; i--)
		{
			if ((p & (1<<i) && Cnt[Go[v].fi]==0) || (!(p & (1<<i)) && Cnt[Go[v].se]==0)) p^= 1<<i;
			if (p & (1<<i)) v = Go[v].fi;
			else v = Go[v].se;
			Cnt[v]--;
		}
		printf ("%d ", p^a);
	}
	printf ("\n");
}