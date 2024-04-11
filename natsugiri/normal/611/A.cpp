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

int x;
char buf[111];
int main() {
    scanf("%d%*s%s", &x, buf);

    if (buf[0] == 'w') {
	if (x == 5 || x == 6) puts("53");
	else puts("52");
    } else {
	if (x <= 29) puts("12");
	else if (x == 30) puts("11");
	else puts("7");
    }
    
    return 0;
}