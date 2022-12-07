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

int n, m, q;
vector<PII> E;
vector<PII> UL;
vector<PII> UR;
int PL[10010];
int PR[10010];
int R[510];

void clearR(){
    FWD(i,1,n+1)
        R[i] = i;
}

int find(int u){
    return R[u]==u?u:(R[u]=find(R[u]));
}

bool unio(int u, int v){
    if(find(u) == find(v)) return 0;
    R[find(u)] = find(v);
    return 1;
}

int main(){
    scanf("%d %d", &n, &m);
    int a, b;
    FWD(i,0,m){
        scanf("%d %d", &a, &b);
        E.push_back(PII(a,b));
    }
    clearR();
    FWD(i,0,m){
        if(unio(E[i].x, E[i].y))
            UL.push_back(E[i]);
        PL[i] = UL.size();
    }
    clearR();
    BCK(i,m-1,-1){
        if(unio(E[i].x, E[i].y))
            UR.push_back(E[i]);
        PR[i] = UR.size();
    }
    PR[m] = 0;
    scanf("%d", &q);
    FWD(i,0,q){
        scanf("%d %d", &a, &b); --a; --b;
        clearR();
        if(a)
            FWD(i,0,PL[a-1])
                unio(UL[i].x, UL[i].y);
        FWD(i,0,PR[b+1])
            unio(UR[i].x, UR[i].y);
        FWD(i,1,n+1) find(i);
        sort(R+1, R+n+1);
        printf("%d\n", (int)(unique(R+1,R+n+1)-R-1));
    }
    return 0;
}