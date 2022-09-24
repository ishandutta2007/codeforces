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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int E(VI a) {
    map<int, int> mp;
    EACH (e, a) mp[*e]++;
    int ma = 0;
    EACH (e, mp) amax(ma, e->second);
    EACH (e, mp) if (ma == e->second) return e->first;
    return -1;
}

int N, M;
int B[111];
int main() {
    scanf("%d%d", &N, &M);
    VI a;
    REP ($, M) {
	REP (i, N) scanf("%d", B+i);
	a.push_back(max_element(B, B+N) - B + 1);
    }
    printf("%d\n", E(a));
    
    return 0;
}