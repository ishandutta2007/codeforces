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

int n, p, k;
int primes[100010];

bool check(){
    for(int i = 0; primes[i] * primes[i] <= k; ++i)
        if(k % primes[i] == 0)
            return 0;
    return 1;
}

int main(){
    scanf("%d", &n);
    primes[0] = 2;
    p = 1;
    k = 3;
    while(p < n){
        if(check())
            primes[p++] = k;
        k += 2;
    }
    FWD(i,0,n)
        printf("%d\n", primes[i]);
    return 0;
}