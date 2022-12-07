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

int n, c, m;
int X[256];
int Y[256];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d %d", &X[i], &Y[i]);
    c = 0;
    FWD(i,0,n){
        m = 0;
        FWD(j,0,n)
            if(X[i] == X[j] && Y[i] < Y[j])
                m |= 1;
            else if(X[i] == X[j] && Y[i] > Y[j])
                m |= 2;
            else if(X[i] < X[j] && Y[i] == Y[j])
                m |= 4;
            else if(X[i] > X[j] && Y[i] == Y[j])
                m |= 8;
        if(m == 15)
            ++c;
    }
    printf("%d\n", c);
    return 0;
}