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

int n, m, k, a, r;
int R[222];
vector<int> V;

inline int f(int x){
    return R[x]==x?x:(R[x]=f(R[x]));
}

inline void u(int a, int b){
    R[f(a)] = f(b);
}

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n+m+5) R[i] = i;
    FWD(i,0,n){
        scanf("%d", &k);
        if(k == 0) ++r;
        FWD(j,0,k){
            scanf("%d", &a);
            u(i, n+a);
        }
    }
    if(r == n) r = 1; else r = 0;
    FWD(i,0,n)
        V.push_back(f(i));
    sort(V.begin(), V.end());
    printf("%d\n", (int)(unique(V.begin(), V.end()) - V.begin())-1+r);
    return 0;
}