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

bool distinct(int n){
    bool D[10];
    FWD(i,0,10)
        D[i] = 0;
    while(n){
        if(D[n%10])
            return 0;
        D[n%10] = 1;
        n /= 10;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    do{++n;}while(!distinct(n));
    printf("%d\n", n);
    return 0;
}