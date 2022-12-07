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

int n, a, f, I;
char buff[200010];

int main(){
    scanf("%d", &n);
    scanf("%s", buff);
    FWD(i,0,n)
        if(buff[i] == 'A')
            ++a;
        else if(buff[i] == 'F')
            ++f;
        else
            ++I;
    if(I == 0)
        printf("%d\n", a);
    else if(I == 1)
        printf("%d\n", 1);
    else
        printf("%d\n", 0);
    return 0;
}