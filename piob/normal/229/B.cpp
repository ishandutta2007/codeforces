#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define pb push_back
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int n, m, a, b, c, r;
vector<PII> E[100010];
vector<int> B[100010];
int A[100010];
int T[100010];
priority_queue<PII> Q;

inline void arrive(int u, int a){
    //printf("arrive %d %d\n", u, a);
    if(u == n){r = min(r, a); return;}
    if(A[u] < a) return;
    int t = 2000000005;
    int b = t;
    while(!B[u].empty() && B[u].back() >= a){
        if(b != B[u].back() + 1)
            t = B[u].back() + 1;
        b = B[u].back();
        //printf("%d %d\n", b, t);
        B[u].pop_back();
    }
    if(b != a) t = a;
    if(t == A[u]) t = T[u];
    T[u] = t;
    A[u] = a;
    //printf("leave %d\n", t);
    Q.push(PII(-t, u));
}

int main(){
    scanf("%d %d", &n, &m);
    r = 2000000005;
    FWD(i,0,m){
        scanf("%d %d %d", &a, &b, &c);
        E[a].pb(PII(b,c));
        E[b].pb(PII(a,c));
    }
    FWD(i,1,n+1){
        scanf("%d", &a);
        FWD(j,0,a){scanf("%d", &b); B[i].push_back(b);}
    }
    FWD(i,1,n+1) A[i] = T[i] = 2000000005;
    arrive(1,0);
    while(!Q.empty()){
        a = Q.top().y;
        Q.pop();
        FE(v,E[a]) arrive(v->x, T[a]+v->y);
    }
    if(r == 2000000005) r = -1;
    printf("%d\n", r);
    return 0;
}