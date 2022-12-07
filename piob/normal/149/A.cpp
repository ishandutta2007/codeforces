#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

//(n - 1) + 2 * (n - 2) + 3 * (n-3) + ... + n
int T[12];

int main(){
    int k;
    scanf("%d", &k);
    FWD(i,0,12) scanf("%d", &T[i]);
    sort(T, T+12, greater<int>());
    int s = 0;
    FWD(i,0,12){
        if(s >= k){printf("%d\n", i); return 0;}
        s += T[i];
    }
    if(s >= k)
        printf("12\n");
    else
        printf("-1\n");
    return 0;
}