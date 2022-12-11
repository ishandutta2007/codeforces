#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool Q;
struct Line{
    mutable ll a;
    mutable ll b;
    mutable ll p;
    bool operator<(const Line &T) const{
        if(Q){
            return p < T.p;
        }
        else{
            return a < T.a;
        }
    }
};

const ll inf = (ll)1e18;

struct Hull : multiset<Line> {
    ll div(ll a, ll b){
        return (a/b-((a^b)<0 && a%b!=0));
    }
    bool check(iterator x, iterator y){
        if(y == end()){
            x->p = inf;
            return false;
        }
        if(x->a == y->a){
            if(x->b >= y->b) x->p = inf;
            else x->p = -inf;
        }
        else{
            x->p = div((x->b)-(y->b), (y->a)-(x->a));
        }
        return x->p >= y->p;
    }
    void add(ll a, ll b){
        Q=false;
        auto it = insert({a, b, 0});
        auto nx = it;
        ++ nx;
        while(check(it,nx)){
            nx = erase(nx);
        }
        nx = it;
        if(nx != begin()){
            -- nx;
            if(check(nx, it)){
                it=erase(it);
                check(nx,it);
            }
        }
        while(1){
            it = nx;
            if(it == begin()) break;
            -- nx;
            if(nx -> p >= it->p){
                it=erase(it);
                check(nx,it);
            }
            else{
                break;
            }
        }
    }
    ll query(ll x){
        Q=true;
        auto it = lower_bound({0, 0, x});
        return ((it->a) * x + (it->b));
    }
};

const int N = (int)1e5 + 9 ;
vector<int> T[N];
Hull lines[N];
ll dp[N];
ll A[N];
ll B[N];

void dfs(int u , int par){
    bool leaf = true;
    for(auto x : T[u]){
        if(x == par) continue;
        leaf = false;
        dfs(x, u );
        if(lines[u].size() > lines[x].size())
            swap(lines[u], lines[x]);
        for(auto t : lines[x]){
            lines[u].add(t.a, t.b);
        }
        lines[x].clear();
    }
    if(leaf){
        lines[u].add(-B[u], 0);
    }
    else{
        dp[u] = -lines[u].query(A[u]);
        lines[u].add(-B[u], -dp[u]);
    }

}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i  ++ ){
        cin >> B[i];
    }
    int u, v;
    for(int i =1 ; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1,-1);
    for(int i = 1; i <= n ; i ++ ){
        cout << dp[i] << " ";
    }
    return 0;
}