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

int n, c, h;
char cur;
char buff[120];

int main(){
    scanf("%s", buff);
    n = strlen(buff);
    h = c = 0;
    cur = buff[0];
    FWD(i,0,n){
        if(h == 5 || cur != buff[i]){
            h = 0;
            ++c;
            cur = buff[i];
        }
        ++h;
    }
    if(h)
        ++c;
    printf("%d\n", c);
    return 0;
}