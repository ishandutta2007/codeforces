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

int N, M;
map<int, int> B;
int A[555];
int main() {
    scanf("%d", &N);

    REP (i, N*N) {
	int b;
	scanf("%d", &b);
	B[b]++;
    }


    REP (i, N) {
	A[i] = B.rbegin()->first;
	printf("%d%c", A[i], i==N-1? '\n' : ' ');
	
	REP (j, i) {
	    int g = __gcd(A[j], A[i]);
	    B[g]-=2;
	}
	B[A[i]] -= 1;
	while (!B.empty() && B.rbegin()->second == 0) {
	    B.erase(B.rbegin()->first);
	}
    }
    return 0;
}