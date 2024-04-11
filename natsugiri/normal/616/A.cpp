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

char A[1000011], B[1000011];
char X[1100011], Y[1100011];
char cmp() {
    int a = strlen(A), b = strlen(B);
    int m = max(a, b);
    REP (i, m) X[i] = Y[i] = '0';
    sprintf(X+m-a, "%s", A);
    sprintf(Y+m-b, "%s", B);

    
    REP (i, m) {
	if (X[i] < Y[i]) return '<';
	if (X[i] > Y[i]) return '>';
    }
    return '=';
}
    

int main() {

    scanf("%s%s", A, B);
    printf("%c\n", cmp());
    return 0;
}