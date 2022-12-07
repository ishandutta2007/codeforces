#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDD pair<long double, long double>
#define x first
#define y second
#define EPS 1e-9
#define INF 1000000009

using namespace std;

int W[210];
int K[210];
vector<int> E[210];
int a, n;

int test(int s){
    int r = 0;
    int Z[210];
    queue<int> Q[4];
    FWD(i,1,n+1){
        Z[i] = K[i];
        if(Z[i] == 0)
            Q[W[i]].push(i);
    }
    while(!Q[1].empty() || !Q[2].empty() || !Q[3].empty()){
        while(!Q[s].empty()){
            a = Q[s].front(); Q[s].pop();
            FE(v,E[a]){
                --Z[*v];
                if(Z[*v] == 0)
                    Q[W[*v]].push(*v);
            }
        }
        if(s == 3) s = 1; else ++s;
        ++r;
    }
    return r;
}

int main(){
    scanf("%d", &n);
    FWD(i,1,n+1) scanf("%d", &W[i]);
    FWD(i,1,n+1){
        scanf("%d", &K[i]);
        FWD(j,0,K[i]){
            scanf("%d", &a);
            E[a].push_back(i);
        }
    }
    printf("%d\n", min(min(test(1), test(2)), test(3) ) + n - 1);
    return 0;
}