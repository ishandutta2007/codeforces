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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), I2=(MOD+1)/2;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

ll facts[MAXN], ifacts[MAXN];
ll nCk(ll n, ll k){
    return facts[n]*ifacts[k]%MOD*ifacts[n-k]%MOD;
}
ll po(ll b, ll p){
    ll r=1; if (!p) return 1;
    for (; p; b=b*b%MOD, p/=2) if (p&1) r=r*b%MOD;
    return r;
}
void solve(){
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (auto& it : a)  cin >> it;
    if (k == 1){ cout << "0\n"; return; }
    facts[0]=ifacts[0]=facts[1]=ifacts[1]=1; for (int i = 2; i < MAXN; i++) facts[i]=i*facts[i-1]%MOD, ifacts[i]=po(facts[i], MOD-2);
    //the only thing that matters is whether im the same as the next one
    //if im different -> k-2 ways to get 0, 1 way to get +1, one way to get -1
    //if if the same -> k ways to get 0
    //easy n^2 dp
    //is the number of ways to win the same as the number of ways to lose?
    //yes, everything is symmetrical
    //so i just need to calculate the number of ways to get 0
    //that is the number of ways to pick +1's such that there are the same number of -1's
    //bruteforce the number of +1's
    //there are n choose ___ number of +1's, and the same number of -1's
    //everything else, (k-2)^
    ll cnt[2]={}; //0 -> diff, 1 -> same
    ll ans=0;
    for (int i = 0; i < n; i++) cnt[a[i]==a[(i+1)%n]]++;
    // cout << cnt[0] << " " << cnt[1] << '\n';
    for (int i = 0; i <= (cnt[0]/2); i++){
        ll j = cnt[0]-2*i;// cout << i << ' ' << j << ' ' << (nCk(cnt[0], i)*nCk(cnt[0]-i, i)%MOD*po(k-2, j)%MOD*po(cnt[1], k)%MOD) << '\n';
        // cout << i << ' ' << j << ' ' << nCk(cnt[0], i) << ' ' << nCk(cnt[0]-i, i) << ' ' << po(k-2, j) << ' ' << po(cnt[1], k) << '\n';
        ans = (ans+nCk(cnt[0], i)*nCk(cnt[0]-i, i)%MOD*po(k-2, j)%MOD*po(k, cnt[1])%MOD)%MOD;
    }
    cout << ((po(k, n)-ans+MOD)%MOD*I2%MOD) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}