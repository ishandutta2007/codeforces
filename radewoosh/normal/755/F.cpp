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

int n, k;

vector <int> wek;

int per[1000007];

int bylo[1000007];

vector <int> moc;

int ile[1000007];

bitset <1000007> dp;
bitset <1000007> pom;
int kied[1000007];

int d=200;

void jebaj()
{
	dp[0]=1;
	int suma=0;
	for (int i=0; i<wek.size(); i++)
		ile[wek[i]]++;
	for (int i=1; i<d && i<=n; i++)
	{
		if (!ile[i])
			continue;
		suma+=i*ile[i];
		for (int j=0; j<=suma; j++)
			kied[j]=1000000000;
		for (int j=0; j<=suma; j++)
			if (dp[j])
				kied[j]=0;
		for (int j=0; j<=suma; j++)
		{
			if (!dp[j] || kied[j]==ile[i] || j+i>n)
				continue;
			dp[j+i]=1;
			kied[j+i]=min(kied[j]+1, kied[j+i]);
		}
	}
	for (int i=d; i<=n; i++)
		for (int j=1; j<=ile[i]; j++)
			dp|=(dp<<i);
			
	printf("%d ", k+(!dp[k]));
}

int main()
{
	scanf("%d%d", &n, &k);
	if (!k)
	{
		printf("0 0\n");
		return 0;
	}
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		int v=i;
		int d=0;
		while(!bylo[v])
		{
			bylo[v]=1;
			d++;
			v=per[v];
		}
		wek.push_back(d);
	}
	sort(wek.begin(), wek.end());
	
	jebaj();
	
	
	moc.clear();
	for (int i=0; i<wek.size(); i++)
	{
		for (int j=1; j<=(wek[i]/2); j++)
			moc.push_back(2);
		if (wek[i]&1)
			moc.push_back(1);
		for (int j=1; j<=(wek[i]/2); j++)
			moc.push_back(0);
	}
	sort(moc.begin(), moc.end());
	reverse(moc.begin(), moc.end());
	for (int i=1; i<n; i++)
		moc[i]+=moc[i-1];
	printf("%d\n", moc[k-1]);
	return 0;
}