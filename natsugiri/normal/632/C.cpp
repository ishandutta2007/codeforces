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


int N;
vector<string> A;
char buf[99];
struct CMP {
    bool operator()(const string &x, const string &y) const {
	return x+y < y+x;
    }
} cmp;
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	A.push_back(buf);
    }
    sort(A.begin(), A.end(), cmp);
    REP (i, A.size()) printf("%s", A[i].c_str());
    puts("");


    return 0;
}