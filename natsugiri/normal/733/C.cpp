#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
int N, K, A[555], B[555];
vector<pair<int, char> > ans;

bool valid(int L, int R) {
    if (R - L == 1) return true;

    int ma = *max_element(A+L, A+R);
    if (count(A+L, A+R, ma) == R - L) return false;

    for (int i=L; i<R-1; i++) {
	if (A[i] == ma && A[i+1] < ma) {
	    REP (j, R-i-1)
		ans.push_back(make_pair(i, 'R'));
	    REP (j, i-L)
		ans.push_back(make_pair(i-j, 'L'));
	    return true;
	}
	if (A[i] < ma && A[i+1] == ma) {
	    REP (j, i-L+1)
		ans.push_back(make_pair(i+1-j, 'L'));
	    REP (j, R-i-2)
		ans.push_back(make_pair(L, 'R'));
	    return true;
	}
    }

    return false;
}


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &K);
    REP (i, K) scanf("%d", B+i);

    int cur = K-1;
    int i, j;
    for (i=N, j=N; cur >= 0; ) {

	int sum = 0;
	while (j > 0 && sum < B[cur]) {
	    j--;
	    sum += A[j];
	}

	if (sum == B[cur]) {
	    if (valid(j, i)) {

		i = j;
		cur--;
	    } else {
		cur = -2;;
		break;
	    }
	} else {
	    cur = -2;
	    break;
	}
    }

    if (cur == -2 || i != 0) {
	puts("NO");
    } else {
	puts("YES");
	REP (t, ans.size()) printf("%d %c\n", ans[t].first + 1, ans[t].second);
    }

    return 0;
}