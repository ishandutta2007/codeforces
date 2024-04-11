#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pii pt;
typedef pair <ll, ll> pll;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll par[N],nep[N],rpar[N],rnep[N],n,a[N];

vector < int > v[N];

ll sol = 0,sol2 = 0;

void dfs(int x,int lst){
    par[x]++;
    for(int i = 0;i<v[x].size();i++){
        if(v[x][i] == lst) continue;
        dfs(v[x][i] , x);
        par[x] += nep[v[x][i]];
        nep[x] += par[v[x][i]];
    }
}

void dfs2(int x,int lst){
    rpar[x] = par[x];
    rnep[x] = nep[x];
    int upp = 0, upn = 0;
    if(lst != -1){
        rpar[x] += rnep[lst] - par[x];
        rnep[x] += rpar[lst] - nep[x];
        upp = rnep[lst] - par[x];
        upn = rpar[lst] - nep[x];
    }
    int sump = upp + 1;
    int sumn = upn;
    for(int i = 0;i<v[x].size();i++){
        if(v[x][i] == lst) continue;
        dfs2(v[x][i], x);
        sump += nep[v[x][i]];
        sumn += par[v[x][i]];
    }
    for(int i = 0;i<v[x].size();i++){
        if(v[x][i] == lst) continue;
        sol += (a[x] * nep[v[x][i]] % MOD + 10 * MOD) % MOD * (sump + sumn - par[v[x][i]] - nep[v[x][i]]) % MOD ;
        sol %= MOD;
        sol -= (a[x] * par[v[x][i]] % MOD + 10 * MOD) % MOD * (sump + sumn - par[v[x][i]] - nep[v[x][i]]) % MOD;
        sol += MOD;sol %= MOD;
    }
    sol += (a[x] * upp % MOD + MOD) % MOD  * (sump + sumn - upp - upn) % MOD;
    sol %= MOD;
    sol -= (a[x] * upn % MOD +  MOD) % MOD  * (sump + sumn - upp - upn)  % MOD;
    sol += MOD;sol %= MOD;
    sol += (a[x] * n % MOD + MOD) % MOD;
    sol %= MOD;

    //sol = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<n-1;i++){
        int x,y;cin >> x >> y;
        v[x].PB(y);
        v[y].PB(x);
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << sol << endl;
    return 0;
}