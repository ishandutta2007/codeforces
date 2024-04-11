#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, q, par[300005], anc[300005][20];
int cen[300005], sub[300005];
vector<int> child[300005];

void dfs1(int x) {
    sub[x] = 1;
    for (int nex: child[x]) {
        dfs1(nex);
        sub[x] += sub[nex];
    }
}

void dfs2(int x) {
    if (child[x].empty()) {
        cen[x] = x;
    } else {
        for (int nex: child[x]) {
            dfs2(nex);
        }
        for (int nex: child[x]) if (sub[nex] > sub[x] / 2) {
            // BUG(x);
            int tmp = cen[nex];
            FORD (j, 19, 0) if (sub[x] / 2 >= sub[anc[tmp][j]]) tmp = anc[tmp][j];
            // BUG(tmp);
            if (sub[x] / 2 >= sub[tmp]) cen[x] = par[tmp];
            else cen[x] = tmp;
            break;
        }
        if (!cen[x]) cen[x] = x;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> q;
    FOR (i, 2, n) {
        cin >> par[i];
        child[par[i]].pb(i);
    }
    par[1] = 1;
    FOR (i, 1, n) anc[i][0] = par[i];
    FOR (j, 1, 19) FOR (i, 1, n) anc[i][j] = anc[anc[i][j - 1]][j - 1];
    dfs1(1);
    dfs2(1);
    while (q--) {
        int val;
        cin >> val;
        cout << cen[val] << endl;
    }
}