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

LL W, M;
vector<LL> X;
bool rec(int i, LL s) {
    if (i == (int)X.size()) {
	return s==0;
    }
    if (s < -2*X[i]) return false;
    return rec(i+1, s-X[i]) || rec(i+1, s) || rec(i+1, s+X[i]);
}

int main() {
    scanf("%lld%lld", &W, &M);

    
    for (LL t=1; t<=M*2; t*=W) X.push_back(t);
    reverse(X.begin(), X.end());
    
    if (W == 2 || rec(0, M)) {
	puts("YES");
    } else {
	puts("NO");
    }

    return 0;
}