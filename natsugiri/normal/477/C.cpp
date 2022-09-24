#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int dp[2011][2011];
int A[2011];

string S, P, Z;
int main() {
    cin >> S >> P;

    while (Z.size() + P.size() <= S.size()) Z += P;

    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = 0;
    REP (i, Z.size()) {
	if (i % P.size() == 0) {
	    REP (j, S.size()) amin(dp[i][j+1], dp[i][j]);
	}

	REP (j, S.size()) {
	    amin(dp[i+1][j+1], dp[i+1][j]+1);
	    if (S[j] == Z[i]) amin(dp[i+1][j+1], dp[i][j]);
	}
    }


    // REP (i, Z.size()+1) {
    // 	REP (j, S.size()+1) {
    // 	    int tmp =dp[i][j];
    // 	    if (tmp ==  0x3f3f3f3f) tmp = -1;
    // 	    cerr << tmp << " ";
    // 	}
    // 	cerr << endl;
    // }

    for (int i=P.size(), c=1; i<=(int)S.size(); i += P.size(), c++) {
	int mi = dp[i][0];
	REP (j, S.size()) amin(mi, dp[i][j+1]);
	if (mi <= (int)S.size()) A[mi] = c;
    }

    REP (i, S.size()) {
	int k = (S.size() - i - 1) / P.size();
	amax(A[i+1], min(A[i], k));
    }

    REP (i, S.size()+1) {
	printf("%d%c", A[i], i == (int)S.size() ? '\n' : ' ');
    }
    return 0;
}