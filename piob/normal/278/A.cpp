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

int n, s, t;
int D[128];

int main(){
    scanf("%d", &n);
    FWD(i,1,n+1){
        scanf("%d", &D[i]);
        D[i] += D[i-1];
    }
    scanf("%d %d", &s, &t);
    --s, --t;
    if(t < s)
        swap(t, s);
    printf("%d\n", min(D[t] - D[s], D[n] - D[t] + D[s]));
    return 0;
}