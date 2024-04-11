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

int N, A[100011];
int ans;
int rec(int k) {
    if (1<<N <= k) return A[k];
    int a = rec(k*2), b = rec(k*2+1);
    ans += abs(a-b);
    return max(a, b) + A[k];
}
int main() {
    scanf("%d", &N);
    for (int i=2; i<(1<<(N+1)); i++) scanf("%d", A+i);
    rec(1);
    printf("%d\n", ans);
    return 0;
}