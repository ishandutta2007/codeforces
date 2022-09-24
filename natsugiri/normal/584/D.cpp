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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

const int MAX = 10000000;
int min_factor[MAX+1];
vector<int>prime;
void make_prime() {
    for (int i=2; i<=MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i<=MAX; i+=3) if (!min_factor[i]) min_factor[i] = 3;
    for (int i=5, d=2; i*i<=MAX; ) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
	i += d; d = 6 - d;
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
	if (min_factor[i]==i) prime.push_back(i);
    }
}

bool is_prime(LL n) {
    if (n<=MAX) return min_factor[n] == n;
    for (int i=0; (LL)prime[i]*prime[i]<=n; i++)
	if (n%prime[i]==0) return false;
    return true;
}

int N;

int main() {
    scanf("%d", &N);
    make_prime();
    if (is_prime(N)) printf("1\n%d\n", N);
    else {
        for (int i=N-2; ; i--) {
            if (is_prime(i)) {
                if (is_prime(N-i)) {
                    printf("2\n%d %d\n", i, N-i);
                    return 0;
                } else {
                    REP (a, prime.size()) REP (b, a+1) {
                        if (N-i == prime[a] + prime[b]) {
                            printf("3\n%d %d %d\n", i, prime[a], prime[b]);
                            return 0;
                        }
                    }
                }
            }
        }
    }


    return 0;
}