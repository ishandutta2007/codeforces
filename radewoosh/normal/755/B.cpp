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

int n, m;

char wcz[10007];

long long tab1[10007];
long long tab2[10007];
int l1, l2;

map < long long,int > mapa;
map < long long,int > juz;

long long hasz()
{
	long long ret1=0;
	for (int i=0; wcz[i]; i++)
		ret1=(ret1*100003+wcz[i])%1000000007;
	long long ret2=0;
	for (int i=0; wcz[i]; i++)
		ret2=(ret2*100003+wcz[i])%1000000009;
	return ret1*1000000009+ret2;
}

bool mniej(long long a, long long b)
{
	return mapa[a]>mapa[b];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz);
		tab1[i]=hasz();
		mapa[tab1[i]]++;
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%s", wcz);
		tab2[i]=hasz();
		mapa[tab2[i]]++;
	}
	sort(tab1+1, tab1+1+n, mniej);
	sort(tab2+1, tab2+1+m, mniej);
	l1=l2=1;
	for (int h=1; 1; h^=1)
	{
		if (h==1)
		{
			while(l1<=n && juz[tab1[l1]])
				l1++;
			if (l1==n+1)
			{
				printf("NO\n");
				return 0;
			}
			juz[tab1[l1]]=1;
			l1++;
		}
		else
		{
			while(l2<=m && juz[tab2[l2]])
				l2++;
			if (l2==m+1)
			{
				printf("YES\n");
				return 0;
			}
			juz[tab2[l2]]=1;
			l2++;
		}
	}
	return 0;
}