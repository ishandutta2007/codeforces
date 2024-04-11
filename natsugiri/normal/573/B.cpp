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

int N;
int H[100011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", H+i+1);
    
    for (int i=1; i<=N; i++) amin(H[i], H[i-1] + 1);
    for (int i=N; i>=1; i--) amin(H[i], H[i+1] + 1);
    int ans = *max_element(H, H+N+2);

    printf("%d\n", ans);

    return 0;
}