//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=57;
using ld=double;

int n;

vi graf[nax];

int jroz[nax][nax];
int roz[nax][nax];

ll kom[nax][nax];
ll pot[nax];

int juzdp[nax][nax];
ld dp[nax][nax][nax][nax];


int liczroz(int a, int b)
{
	if (jroz[a][b])
		return roz[a][b];
	roz[a][b]=1;
	for (int i : graf[b])
		if (i!=a)
			roz[a][b]+=liczroz(b, i);
	jroz[a][b]=1;
	return roz[a][b];
}

ld pom[2][nax][nax];

void czys()
{
	for (int i=0; i<2; i++)
		for (int j=0; j<=n; j++)
			for (int l=0; l<=n; l++)
				pom[i][j][l]=0;
}

void ogardp(int a, int b)
{
	if (juzdp[a][b])
		return;
	int x=0;
	dp[a][b][0][0]=1;
	for (int i : graf[b])
	{
		if (i==a)
			continue;
		ogardp(b, i);
		czys();
		for (int j=0; j<=x; j++)
			for (int l=0; l<=j; l++)
			{
				//~ if (dp[a][b][j][l]>0.01)
					//~ debug() << a << " " << b << " na " << i << " " << j << " " << l;
				pom[0][j][l]=dp[a][b][j][l];
				dp[a][b][j][l]=0;
			}
		int r=roz[b][i];
		//~ debug() << a << " " << b << " na " << i << " " << r;
		for (int jesz=1; jesz<=r; jesz++)
		{
			for (int j=0; j<r; j++)
			{
				for (int l=0; l<=jesz; l++)
				{
					if (j<jesz)
						pom[1][jesz][l+1]+=dp[b][i][j][l]/r;
					else
						pom[1][jesz][l]+=dp[b][i][jesz][l]/r;
				}
			}
		}
		pom[1][0][0]=1;
		//~ if (a==0 && b==2)
			//~ debug() << "kurwa " << pom[0][0][0] << " " << pom[1][1][1];
		for (int j=0; j<=r; j++)
			for (int l=0; l<=j; l++)
				for (int o=0; o<=x; o++)
					for (int w=0; w<=o; w++)
					{
						//~ if (pom[1][j][l]>0.001 && pom[0][o][w]>0.0001 && !a)
							//~ debug() << i << " " << imie(j) << imie(l) << imie(o) << imie(w) << " " << pom[1][j][l] << "*" << pom[0][o][w] << " " << kom[j+o][j] << " " << kom[r+x-j-o][r-j] << " " << kom[r+x][r];
						dp[a][b][j+o][l+w]+=pom[1][j][l]*pom[0][o][w]*(1.0*kom[j+o][j]*kom[r+x-j-o][r-j]/kom[r+x][r]);
					}
		
		//~ dp[a][b][0][0]=1;
		x+=r;
	}
	//~ debug() << a << " " << b << " " << imie(x);
	//~ for (int i=0; i<=x; i++)
		//~ debug() << i << " " << range(dp[a][b][i], dp[a][b][i]+1+i);
	
	
	
	juzdp[a][b]=1;
}

//~ ld wylicz(int a, int b)
//~ {
	//~ ogardp(a, b);
	//~ ld ret=0;
	//~ for (int j=0; j<roz[a][b]; j++)
		//~ ret+=dp[a][b][roz[a][b]-1][j]/pot[j+1];
	//~ debug() << a << " " << b << " " << ret;
	//~ return ret;
//~ }

int main()
{
	scanf("%d", &n);
	pot[0]=1;
	for (int i=1; i<=n; i++)
		pot[i]=pot[i-1]*2;
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=kom[i-1][j]+kom[i-1][j-1];
	}
	
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		liczroz(0, i);
		//~ debug() << imie(roz[0][i]);
	}
	//~ debug() << imie(roz[2][1]);
	
	for (int i=1; i<=n; i++)
	{
		ogardp(0, i);
		ld wyn=0;
		for (int j=0; j<n; j++)
			wyn+=dp[0][i][n-1][j]/pot[j];
		printf("%.11lf\n", (double)wyn);
	}
	//~ printf("%.9lf\n", wylicz(2, 1)*wylicz(2, 4)*wylicz(2, 5));
	return 0;
}