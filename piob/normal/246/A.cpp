#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n;

int main(){
    scanf("%d", &n);
    if(n < 3)
        printf("-1\n");
    else{
        FWD(i,0,n)
            printf("%d\n", n-i);
    }
    return 0;
}