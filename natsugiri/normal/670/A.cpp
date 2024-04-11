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


int main() {
    int N;
    scanf("%d", &N);
    int k = N / 7;
    N %= 7;

    int mi = k * 2;
    if (N >= 6) mi++;
    if (N >= 7) mi++;

    int ma = k * 2;
    if (N >= 1) ma++;
    if (N >= 2) ma++;
    printf("%d %d\n", mi, ma);


    return 0;
}