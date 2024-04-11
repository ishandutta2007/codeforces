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

char buff[16];
int n, m, c;
bool R[16], C[16];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n){
        scanf("%s", buff);
        FWD(j,0,m)
            if(buff[j] == 'S')
                R[i] = C[j] = 1;
    }
    c = 0;
    FWD(i,0,n)
        FWD(j,0,m)
            if(!R[i] || !C[j])
                ++c;
    printf("%d\n", c);
    return 0;
}