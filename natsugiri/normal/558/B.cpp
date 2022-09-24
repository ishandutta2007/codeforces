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

int N;
int le[1000011], cnt[1000011], ri[1000011];
   
int main() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	if (cnt[x] == 0) le[x] = i;
	cnt[x]++;
	ri[x] = i;
    }

    int fr = *max_element(cnt, cnt+1000011);
    int L = 0, R = N;
    REP (i, 1000011) {
	if (cnt[i] == fr && R - L > ri[i] - le[i]) {
	    R = ri[i];
	    L = le[i];
	}
    }

    printf("%d %d\n", L+1, R+1);
    return 0;
}