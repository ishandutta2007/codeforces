#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], nxt[MAXN*MAXK][2], m=0;

ll dfs(int c, int depth){
    //ans for cur
    if (nxt[c][0] == -1 && nxt[c][1] == -1) return 0; //base case
    if (nxt[c][0] == -1 && nxt[c][1] != -1){
        return dfs(nxt[c][1], depth-1);
    } else if (nxt[c][1] == -1 && nxt[c][0] != -1){
        return dfs(nxt[c][0], depth-1);
    } else {
        return (1ll<<depth)^(min(dfs(nxt[c][0], depth-1), dfs(nxt[c][1], depth-1)));
    }
}
void solve(){
    //if i take the most significant bit -> is there anything who is different
    //how do i tie-break -> for each trie node -> 
    cin >> n; memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        int c=0; ll v=a[i];
        for (ll j=MAXK-1; j >= 0; j--){
            if (nxt[c][(v>>j)&1] == -1) nxt[c][(v>>j)&1] = ++m;
            c = nxt[c][(v>>j)&1];
        }
    }
    cout << dfs(0, MAXK-1);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}