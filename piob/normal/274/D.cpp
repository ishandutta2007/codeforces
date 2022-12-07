#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long LL;

int n, m, t, b, a;
vector<int> E[500010];
int V[500010];
int P[500010];
vector<PII> M;
vector<int> R;

void dfs(int u){
    V[u] = 1;
    FE(v, E[u])
        if(!V[*v])
            dfs(*v);
    if(u < m) R.pb(u);
    P[u] = t++;
}

bool check(){
    FWD(i,0,m+b)
        FE(j,E[i])
            if(P[*j] > P[i])
                return 0;
    return 1;
}

int main(){
    cin >> n >> m;
    b = 0;
    FWD(i,0,n){
        M.clear();
        FWD(j,0,m){
            cin >> a;
            if(a != -1)
                M.pb(PII(a, j));
        }
        sort(M.begin(), M.end());
        t = 0;
        FWD(j,0,M.size()){
            if(M[j].x != M[t].x){
                ++b;
                t = j;
            }
            E[M[j].y].pb(m+b);
            E[m+b+1].pb(M[j].y);
            //cout << m+b << " " << M[j].y << " " << m+b+1 << endl;
        }
        b += 2;
    }
    FWD(i,0,m+b) if(!V[i]) dfs(i);
    if(!check()) cout << "-1\n"; else{
        FWD(i,0,m) cout << (R[i]+1) << " ";
        cout << endl;
    }
    return 0;
}