#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define RINT(a) scanf("%d", &a)
#define RLL(a) scanf("%lld", &a)
#define RSTR(a) scanf("%s", a)
#define RDUB(a) scanf("%lf", &a)
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
        #define debug printf
#else
        #define debug
#endif

using namespace std;

int a, b, c, x, y;

int main(){
        scanf("%d %d %d", &a, &b, &c);
        x = a / c;
        y = b / c;
        if( x * c != a) x = x + 1;
        if( y * c != b) y = y + 1;
        printf("%llu\n", ((unsigned long long)x) * ((unsigned long long)y));
        return 0;
}