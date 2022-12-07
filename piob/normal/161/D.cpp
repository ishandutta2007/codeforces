#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <limits>
#include <iostream>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PDD pair<double, double>
#define x first
#define y second
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
    #define debug printf
#else
    #define debug
#endif

using namespace std;

int n, k, a, b;
long long r;
long long d;
int P[50010];
vector<int> E[50010];
int S[50010][510];

void dfs(int u){
    //printf("%d\n", u);
    S[u][0] = 1;
    FE(v,E[u])
        if(P[u] != *v){
            P[*v] = u;
            dfs(*v);
            FWD(i,0,k)
                S[u][i+1] += S[*v][i];
        }
    r += ((long long)S[u][k]);
    d = 0;
    FE(v,E[u])
        if(P[u] != *v)
            FWD(i,1,k)
                d += ((long long)(S[u][i] - S[*v][i-1]) * ((long long)S[*v][k-i-1]));
    r += d / 2LL;
}

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,1,n){
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    P[1] = -1;
    dfs(1);
    cout << r << endl;
    return 0;
}