#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
vector<int> T[N];
set<pii> sub[N];
int answ[N];

void unite(set<pii> &a, set<pii> &b){
    if(a.size() < b.size())swap(a, b);
    for(auto x : b){
        a.insert(x);
    }
    b.clear();
}

int dfs(int u){
    int sbt = 1;
    for(auto x : T[u]){
        sbt += dfs(x);
        unite(sub[u], sub[x]);
    }
    sub[u].insert(mp(sbt, u));
    answ[u] = sub[u].lower_bound(mp((sbt + 1) / 2, -1)) -> se;
    return sbt;
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int p;
    for(int i = 2; i <= n; i ++ ){
        cin >> p;
        T[p].push_back(i);
    }
    dfs(1);
    int ver;
    for(int i = 0 ; i < q; i ++ ){
        cin >> ver;
        cout << answ[ver] << "\n";
    }
    return 0;
}