#include<queue>
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
vector<int>Z_Algorithm(const string&s) {
    int n=s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
	if (i > r) {
	    l = r = i;
	    while (r<n && s[r-l] == s[r]) r++;
	    z[i] = r-l; r--;
	} else {
	    int k = i-l;
	    if (z[k] < r-i+1) z[i] = z[k];
	    else {
		l = i;
		while (r<n && s[r-l] == s[r]) r++;
		z[i] = r-l; r--;
	    }
	}
    }
    return z;
}

int N;
char A[1000111], B[1000111];
string S;


char inverse(char c) {
    if (c == 'N') return 'S';
    if (c == 'S') return 'N';
    if (c == 'E') return 'W';
    if (c == 'W') return 'E';
    return 0;
}


int main() {
    scanf("%d%s%s", &N, A, B);

    reverse(A, A+N-1);

    REP (i, N-1) B[i] = inverse(B[i]);
    
    S = string(A) + "$" + string(B);

    VI z = Z_Algorithm(S);

    for (int i=N; i<2*N-1; i++) {
	if (i+z[i] >= 2*N-1) {
	    puts("NO");
	    return 0;
	}
    }

    puts("YES");

    return 0;
}