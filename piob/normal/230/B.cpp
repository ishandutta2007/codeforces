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

int n;
long long p, a;
bool prime[1000010];

int main(){
    FWD(i,3,1000101)
        prime[i] = (i&1);
    prime[2] = 1;
    for(int i = 3; i <= 999; i+= 2)
        if(prime[i])
            for(int j = i*i; j < 1000010; j += i)
                prime[j] = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%lld", &a);
        p = sqrt(a);
        if(p * p == a && prime[p])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}