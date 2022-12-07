#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, c;
char buff[64];

int main(){
    c = 0;
    scanf("%d%s", &n, buff);
    FWD(i,0,n-1)
        if(buff[i] == buff[i+1])
            ++c;
    printf("%d\n", c);
}