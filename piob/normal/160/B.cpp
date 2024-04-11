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

int n;
char buff[256];

bool check(){
    bool cmp = buff[0] < buff[n];
    FWD(i,0,n)
        if(buff[i] == buff[i+n] || (cmp != (buff[i] < buff[i+n])))
           return 0;
    return 1;
}

int main(){
    scanf("%d", &n);
    scanf("%s", buff);
    sort(buff, buff+n);
    sort(buff+n, buff+2*n);
    printf(check()?"YES":"NO");
    return 0;
}