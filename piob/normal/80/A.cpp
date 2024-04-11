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

int n, m;

bool prime(int p){
    FWD(i,2,p)
        if(p % i == 0)
            return 0;
    return 1;
}

bool check(){
    if(!prime(n))
        return 0;
    if(!prime(m))
        return 0;
    FWD(i,n+1,m)
        if(prime(i))
            return 0;
    return 1;
}

int main(){
    scanf("%d %d", &n, &m);
    printf(check()?"YES":"NO");
    return 0;
}