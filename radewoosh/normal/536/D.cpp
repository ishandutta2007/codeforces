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
sim dor(c) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

void fre() {
#ifndef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int nax=2007;

int n, m;

int s, t;
long long tab[nax];
vector < pair <int,long long> > graf[nax];

long long odl1[nax];
long long odl2[nax];

long long inf=(long long)1000*1000*1000*1000*1000;

queue <int> kol;
int aktu[nax];

int dos1[nax];
int dos2[nax];

int cut1[nax];
int cut2[nax];

int gdz1[nax];
int gdz2[nax];

long long dp[nax][nax][2][2];
int juz[nax][nax][2][2];

int tak[nax][nax];

int juzs[nax];

long long licz(int v, int u, int kto, int mog)
{
	if (tak[v][u])
		return 0;
	if (juz[v][u][kto][mog])
		return dp[v][u][kto][mog];
	if (kto==0)
	{
		dp[v][u][kto][mog]=-inf;
		if (mog && cut1[v])
			dp[v][u][kto][mog]=max(dp[v][u][kto][mog], licz(v, u, 1, 0));
		if (gdz2[dos1[v+1]]<=u)
			dp[v][u][kto][mog]=max(dp[v][u][kto][mog], licz(v+1, u, kto, mog));
		else
			dp[v][u][kto][mog]=max(dp[v][u][kto][mog], licz(v+1, u, kto, 1)+tab[dos1[v+1]]);
	}
	else
	{
		dp[v][u][kto][mog]=inf;
		if (mog && cut2[u])
			dp[v][u][kto][mog]=min(dp[v][u][kto][mog], licz(v, u, 0, 0));
		if (gdz1[dos2[u+1]]<=v)
			dp[v][u][kto][mog]=min(dp[v][u][kto][mog], licz(v, u+1, kto, mog));
		else
			dp[v][u][kto][mog]=min(dp[v][u][kto][mog], licz(v, u+1, kto, 1)-tab[dos2[u+1]]);
	}
	juz[v][u][kto][mog]=1;
	return dp[v][u][kto][mog];
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=m; i++)
	{
		int p1, p2, p3;
		scanf("%d%d%d", &p1, &p2, &p3);
		graf[p1].push_back({p2, p3});
		graf[p2].push_back({p1, p3});
	}
	for (int i=1; i<=n; i++)
	{
		odl1[i]=inf;
		aktu[i]=1;
	}
	odl1[s]=0;
	aktu[s]=0;
	kol.push(s);
	while(!kol.empty())
	{
		int u=kol.front();
		kol.pop();
		if (aktu[u])
			continue;
		aktu[u]=1;
		for (int i=0; i<graf[u].size(); i++)
		{
			int cel=graf[u][i].first;
			if (odl1[u]+graf[u][i].second<odl1[cel])
			{
				odl1[cel]=odl1[u]+graf[u][i].second;
				kol.push(cel);
				aktu[cel]=0;
			}
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		odl2[i]=inf;
		aktu[i]=1;
	}
	odl2[t]=0;
	aktu[t]=0;
	kol.push(t);
	while(!kol.empty())
	{
		int u=kol.front();
		kol.pop();
		if (aktu[u])
			continue;
		aktu[u]=1;
		for (int i=0; i<graf[u].size(); i++)
		{
			int cel=graf[u][i].first;
			if (odl2[u]+graf[u][i].second<odl2[cel])
			{
				odl2[cel]=odl2[u]+graf[u][i].second;
				kol.push(cel);
				aktu[cel]=0;
			}
		}
	}
	for (int i=1; i<=n; i++)
		dos1[i]=dos2[i]=i;
	sort(dos1+1, dos1+1+n, [](int a, int b)->bool{return odl1[a]<odl1[b];});
	sort(dos2+1, dos2+1+n, [](int a, int b)->bool{return odl2[a]<odl2[b];});
	odl1[0]=odl2[0]=-1;
	for (int i=1; i<=n; i++)
	{
		cut1[i]=(odl1[dos1[i]]!=odl1[dos1[i+1]]);
		cut2[i]=(odl2[dos2[i]]!=odl2[dos2[i+1]]);
		gdz1[dos1[i]]=i;
		gdz2[dos2[i]]=i;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			juzs[j]=0;
		int l=0;
		for (int j=1; j<=i; j++)
		{
			l++;
			l-=juzs[dos1[j]];
			juzs[dos1[j]]=1;
		}
		for (int j=1; j<=n; j++)
		{
			l++;
			l-=juzs[dos2[j]];
			juzs[dos2[j]]=1;
			if (l==n)
				tak[i][j]=1;
		}
	}
	tak[0][n]=1;
	tak[n][0]=1;
	long long ret=licz(0, 0, 0, 0);
	if (ret>0)
		printf("Break a heart\n");
	if (ret<0)
		printf("Cry\n");
	if (ret==0)
		printf("Flowers\n");
	return 0;
}