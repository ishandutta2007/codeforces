#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define p2(a) ((a)*(a))

using namespace std;

int n, s, t, c, p;
int P[100010];

int main(){
    scanf("%d%d%d", &n, &s, &t);
    FWD(i,1,n+1)
        scanf("%d", &P[i]);
    if(s == t){
        printf("0\n");
        return 0;
    }
    c = 1;
    p = P[s];
    while(p != s && p != t){
        ++c;
        p = P[p];
    }
    if(p == t)
        printf("%d\n", c);
    else
        printf("-1\n");
    return 0;
}