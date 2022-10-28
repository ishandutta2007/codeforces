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
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    vector<int> cnt(11);
    for (auto it : a){
        string s = to_string(it);
        cnt[sz(s)]++;
    }
    vector<ll> po(50);
    po[0]=1;
    for (int i = 1; i < sz(po); i++) po[i] = po[i-1]*(ll)10%MOD;
    ll ans=0;
    for (auto x : a){
        string s = to_string(x); reverse(s.begin(), s.end());
        for (int dig=0; dig < sz(s); dig++){
            int cur=s[dig]-'0';
            for (int j = 1; j < 11; j++){
                if (j <= dig){
                    //i'm only going to come as the j+dig number
                    // ans = (ans+cur*po[j+dig]*cnt[j]%MOD)%MOD;
                } else {
                    //i can either come as the 2*dig or 2*dig+1
                    ans = (ans+cur*po[2*dig]*cnt[j]%MOD)%MOD;
                    ans = (ans+cur*po[2*dig+1]*cnt[j]%MOD)%MOD;
                }
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}