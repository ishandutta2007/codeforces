#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using pll=pair<ll,ll>;
using vll=vector<ll>;

int n;

vector <pii> mog;

vector <pii> solv;

pii cel={8, 8};

int wspol(pii a, pii b)
{
	return a.first==b.first || a.second==b.second;
}

int odl(pii a, pii b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, -1, 1};

vector <pii> daj(pii a, pii b)
{
	vector <pii> ret;
	while(a!=b)
	{
		for (int i=0; i<4; i++)
		{
			pii c={a.first+rx[i], a.second+ry[i]};
			if (odl(c, b)<odl(a, b))
			{
				a=c;
				if (a!=b)
					ret.push_back(a);
				break;
			}
		}
	}
	return ret;
}

void zrob()
{
	set <pii> juz;
	for (pii i : solv)
		juz.insert(i);
	int jesz=n-solv.size();
	vector <pii> odp{solv[0]};
	solv.push_back(cel);
	for (int i=1; i<(int)solv.size(); i++)
	{
		auto wez=daj(solv[i-1], solv[i]);
		for (pii j : wez)
		{
			if (jesz && !juz.count(j))
			{
				jesz--;
				juz.insert(j);
				odp.push_back(j);
			}
		}
		odp.push_back(solv[i]);
	}
	//~ debug() << odp;
	assert((int)odp.size()==n+1);
	for (int i=0; i<(int)odp.size(); i++)
		for (int j=0; j<i; j++)
			assert(odp[i]!=odp[j]);
	for (int i=1; i<(int)odp.size(); i++)
			assert(wspol(odp[i], odp[i-1]));
	for (pii i : odp)
		printf("%c%d ", (char)('a'+i.first-1), i.second);
	printf("\n");
}

int sumuluj()
{
	auto now=solv;
	now.push_back(cel);
	set <pii> juz;
	for (int i=0; i<(int)now.size(); i++)
		juz.insert(now[i]);
	for (int i=1; i<(int)now.size(); i++)
	{
		auto wez=daj(now[i], now[i-1]);
		for (pii j : wez)
			juz.insert(j);
	}
	
	return juz.size()-1;
}

int main()
{
	mog.push_back({1, 1});
	mog.push_back({8, 1});
	mog.push_back({8, 2});
	mog.push_back({1, 2});
	
	mog.push_back({1, 3});
	mog.push_back({8, 3});
	mog.push_back({8, 4});
	mog.push_back({1, 4});
	
	mog.push_back({1, 5});
	mog.push_back({8, 5});
	mog.push_back({8, 6});
	mog.push_back({1, 6});
	
	mog.push_back({1, 7});
	mog.push_back({8, 7});
	mog.push_back({7, 7});
	mog.push_back({7, 8});
	mog.push_back({1, 8});
	
	scanf("%d", &n);
	for (auto i : mog)
	{
		solv.push_back(i);
		if (!wspol(solv.back(), cel))
			continue;
		int dol=solv.size();
		int gor=sumuluj();;
		if (dol<=n && gor>=n)
		{
			zrob();
			return 0;
		}
	}
	
	assert(0);
	return 0;
}