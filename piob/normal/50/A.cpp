#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a*b/2);
    return 0;
}