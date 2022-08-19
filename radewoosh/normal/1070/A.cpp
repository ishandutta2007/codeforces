# include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
const int dax=507;
const int sax=5007;

int d, s;

int dp[dax][sax];

queue <pii> kol;

int main()
{
	scanf("%d%d", &d, &s);
	for (int i=0; i<d; i++)
		for (int j=0; j<=s; j++)
			dp[i][j]=-1;
	dp[0][0]=0;
	kol.push({0, 0});
	while(!kol.empty())
	{
		pii v=kol.front();
		kol.pop();
		for (int i=0; i<10; i++)
		{
			pii u={(v.first*10+i)%d, v.second+i};
			if (u.second>s)
				continue;
			if (dp[u.first][u.second]!=-1)
				continue;
			dp[u.first][u.second]=dp[v.first][v.second]+1;
			kol.push(u);
		}
	}
	if (dp[0][s]==-1)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=0; i<d; i++)
		for (int j=0; j<=s; j++)
			if (dp[i][j]==-1)
				dp[i][j]=1e9;
	vi pot{1};
	for (int i=0; 1; i++)
	{
		pot.push_back((pot.back()*10)%d);
		for (int j=1; j<10 && j<=s; j++)
		{
			int resz=-pot[i]*j;
			resz%=d;
			resz+=d;
			resz%=d;
			if (dp[resz][s-j]<=i)
			{
				debug << imie(i);
				printf("%d", j);
				int z=s-j;
				for (int l=i-1; l>=0; l--)
				{
					for (int p=0; p<10 && p<=z; p++)
					{
						int terr=resz-pot[l]*p;
						terr%=d;
						terr+=d;
						terr%=d;
						//~ debug << "chce " << l << " " << p << " " << terr << " " << z << "   " << ;
						if (dp[terr][z-p]<=l)
						{
							printf("%d", p);
							z-=p;
							resz=terr;
							break;
						}
					}
				}
				printf("\n");
				return 0;
			}
		}
	}
	return 0;
}