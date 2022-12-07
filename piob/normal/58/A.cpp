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

int n, k;
char hello[] = "hello";
char buff[256];

int main(){
    scanf("%s", buff);
    n = strlen(buff);
    k = 0;
    FWD(i,0,n)
        if(k < 5 && buff[i] == hello[k])
            ++k;
    printf(k == 5 ? "YES" : "NO");
    return 0;
}