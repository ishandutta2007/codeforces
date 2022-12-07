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

long long n;
int a;

int main(){
    a = 0;
    scanf("%lld", &n);
    while(n){
        if(n%10 == 4 || n%10 == 7)
            ++a;
        n /= 10;
    }
    do{
        if(a%10 != 4 && a%10 != 7){
            printf("NO\n");
            return 0;
        }
        a /= 10;
    }while(a);
    printf("YES\n");
    return 0;
}