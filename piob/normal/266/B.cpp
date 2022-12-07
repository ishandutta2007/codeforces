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

int n, t;
char buff[100];

int main(){
    scanf("%d%d%s", &n, &t, buff);
    FWD(i,0,t){
        FWD(j,0,n-1)
            if(buff[j] == 'B' && buff[j+1] == 'G'){
                swap(buff[j], buff[j+1]);
                ++j;
            }
    }
    printf("%s\n", buff);
    return 0;
}