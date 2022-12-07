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

char buff[1024];

int main(){
    scanf("%s", buff);
    if('a' <= buff[0] && buff[0] <= 'z')
        buff[0] += 'A' - 'a';
    printf("%s\n", buff);
    return 0;
}