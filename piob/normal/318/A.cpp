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

long long n, k;

int main(){
    scanf("%lld %lld", &n, &k);
    if(k <= (n+1)/2){
        printf("%lld\n", 2*k-1);
    }else{
        printf("%lld\n", 2*(k-(n+1)/2));
    }
    return 0;
}