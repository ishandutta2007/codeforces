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

const int nax=1007;

int n;

string im[nax];
string naz[nax];

int op[nax];

string daj(int v, int ro)
{
	string ret="";
	ret.push_back(im[v][0]);
	ret.push_back(im[v][1]);
	if (ro==1)
		ret.push_back(im[v][2]);
	else
		ret.push_back(naz[v][0]);
	return ret;
}

int eq(int v, int a, int u, int b)
{
	return (daj(v, a)==daj(u, b));
}

void na2(int v)
{
	if (op[v]==2)
		return;
	op[v]=2;
	for (int i=1; i<=n; i++)
	{
		if (i==v)
			continue;
		if (eq(v, 2, i, op[i]))
			na2(i);
	}
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> im[i] >> naz[i];
		op[i]=1;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			if (eq(i, op[i], j, op[j]))
			{
				na2(i);
				na2(j);
			}
			if (eq(i, 1, j, 1))
			{
				na2(i);
				na2(j);
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			if (eq(i, op[i], j, op[j]))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (int i=1; i<=n; i++)
		cout << daj(i, op[i]) << endl;
	return 0;
}