//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

#include <bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=87;
const int inf=nax*nax;

int n;
char wcz[nax];

int v, k;
int vp[nax];
int kp[nax];
int nn;
int np[nax];

int dp[nax][nax][nax][2];

void mini(int &a, int b)
{
	a=min(a, b);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='V')
		{
			v++;
			vp[v]=i;
			continue;
		}
		if (wcz[i]=='K')
		{
			k++;
			kp[k]=i;
			continue;
		}
		nn++;
		np[nn]=i;
	}
	for (int i=0; i<=nn+2; i++)
		for (int j=0; j<=v+2; j++)
			for (int l=0; l<=k+2; l++)
				dp[i][j][l][0]=dp[i][j][l][1]=inf;
	dp[0][0][0][0]=0;
	debug() << nn << " " << v << " " << k;
	for (int i=0; i<=nn; i++)
	{
		for (int j=0; j<=v; j++)
		{
			for (int l=0; l<=k; l++)
			{
				for (int h=0; h<2; h++)
				{
					if (i<nn)
					{
						int r=0;
						for (int o=1; o<=j; o++)
							if (vp[o]>np[i+1])
								r++;
						for (int o=1; o<=l; o++)
							if (kp[o]>np[i+1])
								r++;
						mini(dp[i+1][j][l][0], dp[i][j][l][h]+r);
					}
					if (j<v)
					{
						int r=0;
						for (int o=1; o<=i; o++)
							if (np[o]>vp[j+1])
								r++;
						for (int o=1; o<=l; o++)
							if (kp[o]>vp[j+1])
								r++;
						mini(dp[i][j+1][l][1], dp[i][j][l][h]+r);
					}
					if (l<k && !h)
					{
						int r=0;
						for (int o=1; o<=i; o++)
							if (np[o]>kp[l+1])
								r++;
						for (int o=1; o<=j; o++)
							if (vp[o]>kp[l+1])
								r++;
						mini(dp[i][j][l+1][0], dp[i][j][l][h]+r);
					}
				}
			}
		}
	}
	printf("%d\n", min(dp[nn][v][k][0], dp[nn][v][k][1]));
	return 0;
}