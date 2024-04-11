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
typedef long long ll;
void fsc(ll &x){
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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

string s;
int cnt[MAXN][ALP];

void solve(){
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < sz(s); i++){
        for (int j = 0; j < ALP; j++){
            cnt[i][j] = (i?cnt[i-1][j]:0)+(s[i]-'a'==j?1:0);
        }
    }
    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r, --l, --r;
        if (l == r){ cout << "Yes\n"; continue; }
        int nm=0;
        for (int i = 0; i < ALP; i++){
            int cur=cnt[r][i]-(l?cnt[l-1][i]:0);
            if (cur) nm++;
        }
        bool bad = (nm <= 2 && s[l] == s[r]);
        cout << (bad?"No\n":"Yes\n");
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}