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
const int MAXN = 3e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first="sjfnb", second="cslnb";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MOD = 998244353;

void solve(){
    //first, can never hit the first condition (other than special case at the start of game or n==1)
    //only losing state is 0,1,2,3,4,5, -> can't remove anything
    int n; cin >> n; map<ll, int> cnt;
    vector<ll> a(n); for (auto& it : a) cin >> it, cnt[it]++;
    sort(a.begin(), a.end());
    if (a.back() == 0){ cout << second; return; }
    if (n == 1){
        cout << (a[0]&1?first:second); return;
    }
    if (cnt[0] > 1){ cout << second; return; }
    int nm=0;
    for (auto& it : cnt)  {
        if (it.second > 2) { cout << second; return; }
        if (it.second > 1) nm++;
        if (it.second > 1 && cnt[it.first-1]){ cout << second; return; }
    }
    if (nm > 1){ cout << second; return; }
    ll s=0;
    for (int i = 0; i < n; i++) {
        if (a[i] < i){ cout << second; return; }
        s += a[i]-i;
    }
    cout << (s&1?first:second);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}