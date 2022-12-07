#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a;scanf("%d",&a);++a;while(--a)
#define PLL pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, r, s, m;
int T[20010];

int main(){
    scanf("%d", &n);
    r = 0;
    FWD(i,0,n){
        scanf("%d", &T[i]);
        r += T[i];
    }
    FWD(k,3,n+1)
        if(n % k == 0){
            m = n / k;
            FWD(i,0,m){
                s = 0;
                FWD(j,0,k)
                    s += T[(i+j*m)%n];
                r = max(s, r);
            }
        }
    printf("%d\n", r);
    return 0;
}