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

int N, K;
pair<int, int> A[111];
int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	A[i] = make_pair(x, i+1);
    }
    sort(A, A+N);
    VI H;
    REP (i, N) {
	if (A[i].first <= K) {
	    H.push_back(A[i].second);
	    K -= A[i].first;
	}
    }
    printf("%d\n", (int)H.size());
    REP (i, H.size()) printf("%d%c", H[i], i+1 == (int)H.size()?'\n':' ');
    return 0;
}