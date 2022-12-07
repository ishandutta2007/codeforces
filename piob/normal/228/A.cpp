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

int T[4];

int main(){
    scanf("%d %d %d %d", &T[0], &T[1], &T[2], &T[3]);
    sort(T, T+4);
    printf("%d\n", (T[0] == T[1]) + (T[1] == T[2]) + (T[2] == T[3]));
    return 0;
}