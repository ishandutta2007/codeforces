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

int n;

bool check(){
    int c = 0;
    while(n){
        if(n % 10 != 1 && n % 10 != 4)
            return 0;
        if(n % 10 == 4)
            ++c;
        else
            c = 0;
        if(c > 2)
            return 0;
        n /= 10;
    }
    return c == 0;
}

int main(){
    scanf("%d", &n);
    printf(check()?"YES":"NO");
    return 0;
}