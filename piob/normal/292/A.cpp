#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

int n, a, b;
int t, q, m;

int main(){
    t = q = m = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d %d", &a, &b);
        q = q - min(q, a-t) + b;
        t = a;
        m = max(m, q);
    }
    printf("%d %d\n", t+q, m);
    return 0;
}