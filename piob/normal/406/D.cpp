#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), (a).end())
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int n;
LL X[100010];
LL Y[100010];
int nxt[100010];
int jmp[100010][18];
int depth[100010];

bool check(int i, int j, int k){
    return (X[j] - X[i]) * (Y[k] - Y[i]) > (X[k] - X[i]) * (Y[j] - Y[i]);
}

int dfs(int u){
    if(depth[u])
        return depth[u];
    return (depth[u] = dfs(nxt[u]) + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    FWD(i,0,n)
        cin >> X[i] >> Y[i];
    nxt[n-1] = n-1;
    BCK(i,n-2,-1){
        nxt[i] = i+1;
        while(check(i,nxt[i],nxt[nxt[i]]))
            nxt[i] = nxt[nxt[i]];
    }
    depth[n-1] = 1;
    FWD(i,0,n-1)
        if(depth[i] == 0)
            dfs(i);
    BCK(i,n-1,-1){
        jmp[i][0] = nxt[i];
        FWD(j,1,18)
            jmp[i][j] = jmp[jmp[i][j-1]][j-1];
    }
    int q;
    cin >> q;
    FWD(_q,0,q){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if(depth[a] < depth[b]) swap(a,b);
        BCK(i,17,-1)
            if(depth[jmp[a][i]] >= depth[b])
                a = jmp[a][i];
        BCK(i,17,-1)
            if(jmp[a][i] != jmp[b][i])
                a = jmp[a][i], b = jmp[b][i];
        if(a != b)
            a = jmp[a][0];
        printf("%d ", a+1);
    }
    printf("\n");
    return 0;
}