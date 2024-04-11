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

using namespace std;

int x, y, z;

int main(){
    scanf("%d %d %d", &x, &y, &z);
    printf("%d\n", (int)(4*(sqrt(x*y/z)+sqrt(y*z/x)+sqrt(z*x/y))));
    return 0;
}