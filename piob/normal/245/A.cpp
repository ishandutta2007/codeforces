#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <limits>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PDD pair<double, double>
#define x first
#define y second
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
    #define debug printf
#else
    #define debug
#endif

using namespace std;

int n, t, x, y;
int X[2], Y[2];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d %d %d", &t, &x, &y);
        --t;
        X[t] += x;
        Y[t] += y;
    }
    FWD(i,0,2)
        if(X[i] >= Y[i])
            printf("LIVE\n");
        else
            printf("DEAD\n");
    return 0;
}