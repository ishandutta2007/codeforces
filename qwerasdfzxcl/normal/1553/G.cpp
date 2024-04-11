#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct DSU{
    int path[300300];
    void init(int n){
        for (int i=1;i<=n;i++) path[i] = i;
    }
    int find(int s){
        if (s==path[s]) return s;
        return path[s] = find(path[s]);
    }
    void merge(int s, int v){
        int x = find(s), y = find(v);
        if (x==y) return;
        path[x] = y;
    }
}dsu, dsu2;
int a[150150];
unordered_set<int> adj[150150];
bool prime[1001000];
vector<int> P, fact[300300];

void sieve(int mx){
    fill(prime+2, prime+mx, 1);
    for (int i=2;i<mx;i++){
        if (!prime[i]) continue;
        P.push_back(i);
        for (int j=2;i*j<mx;j++) prime[i*j] = 0;
    }
}

void factorize(int n, vector<int> &ret){
    for (int i=0;i<(int)P.size();i++){
        if (n==1 || (ll)P[i]*P[i]>(ll)n) break;
        if (!(n%P[i])) ret.push_back(i);
        while(!(n%P[i])) n /= P[i];
    }
    if (n!=1) ret.push_back(lower_bound(P.begin(), P.end(), n) - P.begin());
}

void solve(){
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (dsu2.find(fact[x][0])==dsu2.find(fact[y][0])){
        printf("0\n");
    }
    else{
        int tmp1 = dsu2.find(fact[x][0]), tmp2 = dsu2.find(fact[y][0]);
        if (adj[tmp1].find(tmp2)!=adj[tmp1].end()) printf("1\n");
        else printf("2\n");
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    sieve(1001000);
    dsu2.init(300299);
    for (int i=0;i<n;i++){
        cin >> a[i];
        factorize(a[i], fact[i]);
        factorize(a[i]+1, fact[i+n]);
        for (int j=0;j<(int)fact[i].size();j++){
            for (int k=j+1;k<(int)fact[i].size();k++) dsu2.merge(fact[i][j], fact[i][k]);
        }

    }

    for (int i=0;i<n;i++){
        int tmp = dsu2.find(fact[i][0]);
        for (auto &x:fact[i+n]){
            adj[tmp].insert(dsu2.find(x));
            adj[dsu2.find(x)].insert(tmp);
            for (auto &y:fact[i+n]){
                adj[dsu2.find(x)].insert(dsu2.find(y));
                adj[dsu2.find(y)].insert(dsu2.find(x));
            }
        }
    }

    while(q--){
        solve();
    }
    return 0;
}