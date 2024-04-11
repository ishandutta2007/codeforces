#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FOR(a,b,c) for(int a=(b); a<(c); ++a)
#define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
#define REP(a,b) for(int a=0; a<(b); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDD pair<long double, long double>
#define x first
#define y second
#define EPS 1e-9
#define INF 1000000009

using namespace std;

typedef long long LL;

int x, y, a, b;

inline int gcd(int a, int b){
    while(a&&b) a>b?a%=b:b%=a;
    return a+b;
}

inline int cnt(int c){
    return c / (x * y / gcd(x, y));
}

int main(){
    scanf("%d %d %d %d", &x, &y, &a, &b);
    printf("%d\n", cnt(b) - cnt(a-1));
    return 0;
}