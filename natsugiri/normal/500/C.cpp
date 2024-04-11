#include<deque>
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

int N, M, W[555];
bool use[555];
vector<int> ans;

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", W+i);

    deque<int> D;
    LL ans = 0;
    REP (i, M) {
	int P;
	scanf("%d", &P); P--;

	if (!use[P]) D.push_back(P);
	use[P] = true;
	
	deque<int> nxt;
	LL sum = 0;
	REP (i, D.size()) {
	    if (D[i] == P) {
		ans += sum;
	    } else {
		nxt.push_back(D[i]);
		sum += W[D[i]];
	    }
	}
	nxt.push_front(P);
	swap(D, nxt);
    }

    printf("%lld\n", ans);
    return 0;
}