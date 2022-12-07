#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, c, d;
char buff[256];

int main(){
    d = 0, c = 1;
    scanf("%s", buff);
    n = strlen(buff);
    FWD(i,1,n){
        if(buff[i] == buff[i-1])
            ++c;
        else
            c = 1;
        if(c > 6)
            d = 1;
    }
    printf(d?"YES":"NO");
}