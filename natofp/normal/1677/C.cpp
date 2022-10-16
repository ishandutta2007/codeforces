#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int nax = 1e5 + 5;
int a[nax];
int b[nax];
int n;

bool vis[nax];
int sz;
vector<int> adj[nax];

void dfs(int v){
    vis[v] = true;
    sz += 1;
    for(int x : adj[v]){
        if(!vis[x]) dfs(x);
    }
}

bool cmp(int x, int y){
    return x > y;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) adj[a[i]].pb(b[i]);
    fill(vis + 1, vis + n + 1, false);
    vector<int> v;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sz = 0;
            dfs(i);
            v.pb(sz);
        }
    }
    sort(v.begin(), v.end(), cmp);
    set<int> can;
    for(int i=1;i<=n;i++) can.insert(i);
    int mid = (n + 1) / 2;
    int jmp = 1;
    vector<int> gut;
    for(int x : v){
        if(x & 1){
            gut.pb(x - 1);
            can.erase(mid);
            if(jmp & 1){
                mid += jmp;
            }
            else mid -= jmp;
            jmp++;
        }
        else gut.pb(x);
    }
    int sz = can.size();
    deque<int> L, R;
    mid = (n + 1) / 2;
    if(can.size() == n){
        auto it = (can.begin());
        for(int i=0;i<sz;i++){
            if(i < sz / 2) L.push_back(*it);
            else R.push_back(*it);
            it++;
        }
    }
    else{
        for(int x : can){
            if(x < mid) L.pb(x);
            else R.pb(x);
        }
    }
    for(int x : gut){
        if(x == 0) continue;
        vector<int> cur;
        int tmp = x;
        int xd = 0;
        if(L.size() < R.size()) xd = 1;
        while(tmp--){
            if(xd == 0){
                cur.pb(L.front());
                L.pop_front();
            }
            else{
                cur.pb(R.back());
                R.pop_back();
            }
            xd ^= 1;
        }
        for(int i=1;i<cur.size();i++) ans += abs(cur[i] - cur[i - 1]);
        ans += abs(cur.back() - cur[0]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}