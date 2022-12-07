#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, a, m;
map<int, int> M;

int main(){
    scanf("%d", &n);
    m = 0;
    FWD(i,0,n){
        scanf("%d", &a);
        ++M[a];
        m = max(m, M[a]);
    }
    printf("%d %d\n", m, M.size());
    return 0;
}