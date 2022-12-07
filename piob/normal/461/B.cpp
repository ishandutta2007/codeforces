#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int mod = 1000000007;

int n;
vector<int> sons[100010];
LL M[2][100010];
int C[100010];

void dfs(int u){
    LL zero, one;
    zero = 1-C[u];
    one = C[u];
    for(int v : sons[u]){
        dfs(v);
        one = (one * M[1][v] + one * M[0][v] + zero * M[1][v]) % mod;
        zero = (zero * M[1][v] + zero * M[0][v]) % mod;
    }
    M[0][u] = zero;
    M[1][u] = one;
}

int main(){
    scanf("%d", &n);
    FWD(i,1,n){
        int p;
        scanf("%d", &p);
        sons[p].push_back(i);
    }
    FWD(i,0,n) scanf("%d", &C[i]);
    dfs(0);
    printf("%d\n", (int)M[1][0]);
    return 0;
}