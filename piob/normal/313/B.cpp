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

int n, a, b;
char buff[100010];
int S[100010];

int main(){
    scanf("%s", buff);
    n = strlen(buff);
    FWD(i,1,n+1)
        S[i] = S[i-1] + (buff[i-1] == buff[i]);
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d%d", &a, &b);
        printf("%d\n", S[b-1] - S[a-1]);
    }
    return 0;
}