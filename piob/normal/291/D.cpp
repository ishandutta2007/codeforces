#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int T[10010];

int main(){
    int n, k, m;
    scanf("%d %d", &n, &k);
    FWD(i,1,n) T[i] = 1;
    T[n] = 0;
    FWD(i,0,k){
        m = 1;
        FWD(i,1,n+1){
            while(T[i] + T[m] > n - i) ++m;
            T[i] += T[m];
            printf("%d ", m);
            m = max(i+1, m);
        }
        printf("\n");
    }
}