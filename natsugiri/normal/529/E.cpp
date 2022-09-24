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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, K, A[5111], Q, X;
map<int, int> mp;
int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) {
        for (int j=1; j<=K; j++) {
            if (mp.count(A[i]*j)) amin(mp[A[i]*j], j);
            else mp[A[i]*j] = j;
        }
    }

    mp[0] = 0;
    scanf("%d", &Q);

    REP ($, Q) {
        scanf("%d", &X);
        int ans = K+1;
        REP (i, N) {
            for (int j=1; j<=K; j++) {
                if (A[i]*j > X) break;
                if (mp.count(X-A[i]*j)) amin(ans, j+mp[X-A[i]*j]);
            }
        }
        if (ans == K+1) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}