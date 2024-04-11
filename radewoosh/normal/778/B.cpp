#ifndef LOCAL
#define NDEBUG
#endif

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

const int nax=5007;

int n, m;

int l;
map <string,int> szyf;

int typ[nax];//0   , and, or, xor
bitset <nax> kon[nax];

int raz[nax];
int dwa[nax];

string wcz, gow;

int war[nax][2];

vector <int> wmin, wmax;

int spyt(string &s)
{
	if (s=="?")
		return -1;
	if (!szyf.count(s))
	{
		l++;
		szyf[s]=l;
	}
	return szyf[s];
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> wcz;
		spyt(wcz);
		cin >> gow;
		cin >> wcz;
		if (wcz[0]=='0' || wcz[0]=='1')
		{
			typ[i]=0;
			for (int j=0; j<m; j++)
				kon[i][j+1]=(wcz[j]-'0');
		}
		else
		{
			raz[i]=spyt(wcz);
			
			cin >> wcz;
			if (wcz[0]=='A')
				typ[i]=1;
			if (wcz[0]=='O')
				typ[i]=2;
			if (wcz[0]=='X')
				typ[i]=3;
			
			cin >> wcz;
			dwa[i]=spyt(wcz);
		}
	}
	
	for (int j=1; j<=m; j++)
	{
		int sum[]={0, 0};
		for (int i=1; i<=n; i++)
		{
			if (typ[i]==0)
			{
				war[i][0]=kon[i][j];
				war[i][1]=kon[i][j];
			}
			for (int h=0; h<2; h++)
			{
				int w1, w2;
				if (raz[i]==-1)
					w1=h;
				else
					w1=war[raz[i]][h];
				if (dwa[i]==-1)
					w2=h;
				else
					w2=war[dwa[i]][h];
				if (typ[i]==1)
				{
					war[i][h]=(w1&w2);
				}
				if (typ[i]==2)
				{
					war[i][h]=(w1|w2);
				}
				if (typ[i]==3)
				{
					war[i][h]=(w1^w2);
				}
				sum[h]+=war[i][h];
			}
		}
		if (sum[0]<=sum[1])
			wmin.push_back(0);
		else
			wmin.push_back(1);
		if (sum[0]>=sum[1])
			wmax.push_back(0);
		else
			wmax.push_back(1);
	}
	
	for (int i=0; i<m; i++)
		printf("%d", wmin[i]);
	printf("\n");
	for (int i=0; i<m; i++)
		printf("%d", wmax[i]);
	printf("\n");
	return 0;
}