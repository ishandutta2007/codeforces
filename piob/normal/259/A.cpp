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

char buff[16][16];

int main(){
    FWD(i,0,8)
        scanf("%s", buff[i]);
    FWD(i,0,8)
        FWD(j,1,8)
            if(buff[i][j] == buff[i][j-1]){
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    return 0;
}