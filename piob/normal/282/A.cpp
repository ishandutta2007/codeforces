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
char buff[10];

int main(){
    c = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%s", buff);
        if(buff[1] == '+')
            ++c;
        else
            --c;
    }
    printf("%d\n", c);
}