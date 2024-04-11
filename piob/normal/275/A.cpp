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

int T[5][5];

int main(){
    FWD(i,1,4)
        FWD(j,1,4)
            scanf("%d", &T[i][j]);
    FWD(i,1,4){
        FWD(j,1,4)
            printf("%d", 1 - (T[i][j] + T[i-1][j] + T[i+1][j] + T[i][j-1] + T[i][j+1]) % 2);
        printf("\n");
    }
    return 0;
}