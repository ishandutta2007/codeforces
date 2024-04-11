#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n;
char buff[256];

int main(){
    int t; scanf("%d", &t); while(t--){
        scanf("%s", buff);
        n = strlen(buff);
        if(n > 10)
            printf("%c%d%c\n", buff[0], n-2, buff[n-1]);
        else
            printf("%s\n", buff);
    }
    return 0;
}