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
const int MAX = 10000;
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

int N;
int main() {
    make_prime();
    scanf("%d", &N);
    VI ans;
    for (int i=0; prime[i] <= N; i++) {
	int m = prime[i];
	while (N >= m) {
	    ans.push_back(m);
	    m *= prime[i];
	}
    }
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i], i+1==(int)ans.size()? '\n': ' ');
    return 0;
}