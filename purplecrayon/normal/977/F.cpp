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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 24, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6, MAXB = 20, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], nxt[MAXN];
map<int, ar<int, 2>> mp; //mx, idx

void add(ll& a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
}
void solve(){
    fsc(n);
    for (int i = 0; i < n; i++) fsc(a[i]);
    for (int i = n-1; i >= 0; i--){
        if (mp.count(a[i]+1)){
            nxt[i] = mp[a[i]+1][1];
            mp[a[i]] = max(mp[a[i]], {1+mp[a[i]+1][0], i});
        } else {
            nxt[i] = -1;
            mp[a[i]] = max(mp[a[i]], {1, i});
        }
    }
    int st=-1;
    for (auto& it : mp) if (st == -1 || it.second[0] > mp[st][0]) st = it.first;
    cout << mp[st][0] << '\n';
    int c = mp[st][1];
    while (c != -1){
        cout << (c+1) << ' ';
        c = nxt[c];
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}