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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

char S[555];
string C = "CODEFORCES"; // 10
int main() {
    scanf("%s", S);
    string X = S;
    int N = strlen(S);

    for (int i=0; i<N; i++) {
	for (int j=i+1; j<=N; j++) {
	    if (C == X.substr(0, i) + X.substr(j)) {
		puts("YES");
		return 0;
	    }
	}
    }
    puts("NO");
    return 0;
}