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

int a;

int main(){
    FWD(i,0,5)
        FWD(j,0,5){
            scanf("%d", &a);
            if(a == 1)
                printf("%d\n", abs(2-i) + abs(2-j));
        }
    return 0;
}