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


int main() {
    int n;
    scanf("%d", &n);
    int a = 2, b = 1;
    if (n & 1) swap(a, b);
    
    for (int i=a; i<n; i+=2) printf("%d ", i);
    printf("%d ", n);
    for (int i=n-2; i>=a; i-=2) printf("%d ", i);
    printf("%d ", n);
	
    for (int i=b; i<n; i+=2) printf("%d ", i);
    for (int i=n-1; i>=b; i-=2) printf("%d ", i);
    puts("");
    return 0;
}