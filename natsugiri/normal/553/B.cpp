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

int N;
VI ans;

LL fib[99];
bool rec(int I, LL k) {
    if (I > N) {
//	eprintf("%lld\n", k);
	return true;
    }

    int r = N-I+1;
    if (fib[r] >= k) {
	ans.push_back(I);
	rec(I+1, k);
    } else {
	ans.push_back(I+1); ans.push_back(I);
	rec(I+2, k-fib[r]);
    }
    return false;
}


LL K;

int main() {
    fib[1] = 1;
    for (int i=2; i<99; i++) fib[i] = fib[i-1] + fib[i-2];
    
    scanf("%d%lld", &N, &K);
    rec(1, K);

    REP (i, N) printf("%d%c", ans[i], i+1==N? '\n' : ' ');
    
    return 0;
}