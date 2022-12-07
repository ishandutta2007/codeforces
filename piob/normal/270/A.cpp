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

bool check(int a){
    FWD(i,3,361)
        if(360 % i == 0 && 180 - 360/i == a)
            return 1;
    return 0;
}

int n, a;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        if(check(a))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}