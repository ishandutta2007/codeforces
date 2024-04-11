#include<queue>
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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }


int N, K[2];
queue<int> qu[2];

int main() {
    scanf("%d", &N);
    REP (i, 2) {
        scanf("%d", K+i);
        REP (j, K[i]) {
            int x;
            scanf("%d", &x);
            qu[i].push(x);
        }
    }

    const int X = 100000;
    int H[2] = {};
    REP ($, X+1) {
        if ($ == X) {
            puts("-1");
            return 0;
        }

        if (qu[0].empty() || qu[1].empty()) {
            printf("%d %d\n", $, qu[0].empty() ? 2 : 1);
            break;
        }
        H[0] = qu[0].front(); qu[0].pop();
        H[1] = qu[1].front(); qu[1].pop();
        if (H[0] < H[1]) {
            qu[1].push(H[0]);
            qu[1].push(H[1]);
        } else {
            qu[0].push(H[1]);
            qu[0].push(H[0]);
        }
    }

    return 0;
}