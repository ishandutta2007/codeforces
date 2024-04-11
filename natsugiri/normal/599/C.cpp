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
pair<int, int> H[100011];
int B[100011];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", &H[i].first);
	H[i].second = i;
    }
    sort(H, H+N);

    REP (i, N) {
	if (i < H[i].second) {
	    B[i]++;
	    B[H[i].second]--;
	} else {
	    B[i]--;
	    B[H[i].second]++;
	}
    }

    REP (i, N) B[i+1] += B[i];

    int cnt = 1;
    REP (i, N-1) if (B[i] == 0) cnt++;
    printf("%d\n", cnt);
    return 0;
}