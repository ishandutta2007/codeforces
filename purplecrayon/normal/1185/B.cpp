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
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first="tokitsukaze", second="quailty", draw="once again";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MOD = 998244353;

void solve(){
    auto get = [&](string s){
        vector<pair<char, int>> v;
        for (auto c : s){
            if (sz(v) && v.back().first == c) v.back().second++;
            else v.push_back({c, 1});
        }
        return v;
    };
    string s, t; cin >> s >> t;
    auto a1=get(s), a2=get(t);
    if (sz(a1) != sz(a2)) { cout << no; return; }
    for (int i = 0; i < sz(a1); i++) if (a1[i].first != a2[i].first || a1[i].second > a2[i].second){ cout << no; return; }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}