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
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int N;
LL M;
deque<int> P;

void rec(int i) {
    int r = N-i+1;
    if (i==1) {
	P.push_back(r);
    } else {
	LL x = 1LL<<(i-2);
	if (M < x) {
	    rec(i-1);
	    P.push_front(r);
	} else {
	    M -= x;
	    rec(i-1);
	    P.push_back(r);
	}
    }
}

int main() {
    scanf("%d%lld", &N, &M);
    M--;
    rec(N);

    REP (i, N) printf("%d%c", P[i], i+1==N ? '\n' : ' ');
    cerr << M << "\n";
    return 0;
}