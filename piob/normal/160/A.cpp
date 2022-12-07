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

int n, s, h, T[128];

int main(){
    s = h = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &T[i]);
        s += T[i];
    }
    sort(T, T+n, greater<int>());
    FWD(i,0,n){
        h += T[i];
        if(h > s-h){
            printf("%d\n", i+1);
            return 0;
        }
    }
}