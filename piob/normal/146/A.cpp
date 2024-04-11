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

int n, s;
char buff[128];

int main(){
    scanf("%d%s", &n, buff);
    FWD(i,0,n){
        if(buff[i] != '4' && buff[i] != '7'){
            printf("NO\n");
            return 0;
        }
        if(i < n/2)
            s += buff[i];
        else
            s -= buff[i];
    }
    printf(s==0?"YES\n":"NO\n");
    return 0;
}