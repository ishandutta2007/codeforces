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

const int nax=1000*1007;

int n, m;

char tek[nax];
char wzo[nax];

int per[nax];
int kied[nax];

int check(int v)
{
	int l=0;
	for (int i=1; i<=n; i++)
	{
		if (kied[i]<=v)
			continue;
		if (l<m && wzo[l+1]==tek[i])
			l++;
	}
	return (l==m);
}

int main()
{
	scanf("%s%s", tek+1, wzo+1);
	n=strlen(tek+1);
	m=strlen(wzo+1);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &per[i]);
		kied[per[i]]=i;
	}
	int bsa, bsb, bss;
	bsa=0;
	bsb=n;
	while(bsa<bsb)
	{
		bss=(bsa+bsb+2)>>1;
		if (check(bss))
			bsa=bss;
		else
			bsb=bss-1;
	}
	printf("%d\n", bsa);
	return 0;
}