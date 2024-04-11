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

int N, A[3], B[3];
int main() {
    scanf("%d", &N);
    REP (i, 3) scanf("%d%d", A+i, B+i);
    VI ans;
    int k;
    k = min(B[0], N-A[1]-A[2]);
    ans.push_back(k);
    N -= k;
    k = min(B[1], N-A[2]);
    ans.push_back(k);
    N -= k;
    ans.push_back(N);

    REP (i, 3) printf("%d\n", ans[i]);
    return 0;
}