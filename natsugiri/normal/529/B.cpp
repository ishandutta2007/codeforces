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

int N, W[1011], H[1011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", W+i, H+i);


    LL ans = 1LL<<60;
    for (int G=1; G<=1000; G++) {
        vector<int> D;
        LL sumW = 0;
        bool ok = true;
        int cnt = 0;
        REP (i, N) {
            if (H[i] > G && W[i] > G) { ok = false; break; }
            if (H[i] > G) {
                cnt++;
                sumW += H[i];
            } else {
                if (H[i] < W[i] && W[i] <= G) D.push_back(W[i]-H[i]);
                sumW += W[i];
            }
        }
        if (!ok || cnt > N/2) continue;
        sort(D.begin(), D.end());

        for (int i=0; i<(int)D.size() && i+1+cnt<=N/2; i++)
            sumW -= D[D.size()-1-i];

        amin(ans, G*sumW);
    }
    printf("%lld\n", ans);
    return 0;
}