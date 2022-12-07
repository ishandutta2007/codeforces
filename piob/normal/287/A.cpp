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

char S[7][7];

inline bool test(int i, int j){
    int c = 0;
    FWD(a,0,2)
        FWD(b,0,2)
            c += (S[i+a][j+b] == '.');
    return c != 2;
}

inline bool check(){
    FWD(i,0,3)
        FWD(j,0,3)
            if(test(i,j))
                return 1;
    return 0;
}

int main(){
    FWD(i,0,4)
        scanf("%s", S[i]);
    printf(check()?"YES":"NO");
    return 0;
}