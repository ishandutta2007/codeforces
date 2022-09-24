#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

LL gcd(LL x, LL y) {
    while (y) {
	x %= y;
	swap(x, y);
    }
    return x;
}
int N, L[333], C[333];
map<int, int> mp;
int main() {
    scanf("%d", &N);

    REP (i, N) scanf("%d", L+i);
    REP (i, N) scanf("%d", C+i);
    REP (i, N) {
	vector<pair<int, int> > v;
	v.push_back(make_pair(L[i], C[i]));
	EACH (e, mp) {
	    v.push_back(make_pair(gcd(L[i], e->first), C[i]+e->second));
	}
	EACH (e, v) {
	    if (mp.count(e->first)) amin(mp[e->first], e->second);
	    else mp[e->first] = e->second;
	}
    }

    if (mp.count(1)) printf("%d\n", mp[1]);
    else puts("-1");
    return 0;
}