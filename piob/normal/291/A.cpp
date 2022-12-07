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

int n;
map<LL, int> M;

int solve(){
    int a;
    FWD(i,0,n){
        scanf("%d", &a);
        if(a) ++M[a];
    }
    a = 0;
    FE(m,M)
        switch(m->y){
            case 1: break;
            case 2: ++a; break;
            default: return -1;
        }
    return a;
}

int main(){
    scanf("%d", &n);
    printf("%d\n", solve());
    return 0;
}