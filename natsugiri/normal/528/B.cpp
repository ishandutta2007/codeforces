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

int N;
pair<LL, LL> E[200111];
int main() {
    scanf("%d", &N);
    REP (i, N) {
        LL x, w;
        scanf("%lld%lld", &x, &w);
        E[i] = make_pair(x+w, x-w);
    }
    sort(E, E+N);

    int ans = 0;
    LL last = - (1LL<<60);
    REP (i, N) {
        // cerr << E[i].second << " " << E[i].first << "\n";
        if (last <= E[i].second) {
            ans++;
            amax(last, E[i].first);
        }
    }

    printf("%d\n", ans);
    return 0;
}