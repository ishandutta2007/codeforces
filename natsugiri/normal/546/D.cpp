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

const int MAX = 5000011;
bool prime[MAX];
LL F[MAX];

int main() {
    for (int i=2; i<MAX; i++) prime[i] = 1;
    for (int i=2; i<MAX; i++) {
        if (prime[i]) {
            for (LL j=(LL)i*i; j<MAX; j += i) prime[j] = 0;
            for (LL j=i; j<MAX; j*=i) {
                for (LL k=j; k<MAX; k+=j) {
                    F[k] += 1;
                }
            }
        }
    }

    REP (i, MAX-1) F[i+1] += F[i];
    
    int T, A, B;
    scanf("%d", &T);
    REP ($, T) {
        scanf("%d%d", &A, &B);
        printf("%lld\n", F[A] - F[B]);
    }
          
    return 0;
}