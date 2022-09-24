#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }


string S;

int main() {
    cin >> S;

    LL odd_ans = 0, even_ans = 0;
    LL a0, a1, b0, b1;
    a0 = a1 = b0 = b1 = 0;

    REP (i, S.size()) {
	if (S[i] == 'a') {
	    if (i % 2) {
		a1++;
		odd_ans += a1;
		even_ans += a0; 
	    } else {
		a0++;
		odd_ans += a0;
		even_ans += a1;
	    }
	} else {
	    if (i % 2) {
		b1++;
		odd_ans += b1;
		even_ans += b0; 
	    } else {
		b0++;
		odd_ans += b0;
		even_ans += b1;
	    }
	}
    }

    printf("%lld %lld\n", even_ans, odd_ans);

    return 0;
}