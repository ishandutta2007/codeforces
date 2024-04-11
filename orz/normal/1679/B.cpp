#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define print(vect) for(auto it : vect) cout << it << ' '; cout << endl
#define print1(m) for(auto it : mp) cout << it.F << ' ' << it.S << endl
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int,int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int M = 1e9 + 7;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// A.order_of_key(X) - Finding no. of elements smaller than X in the set
// *A.find_by_order(X) - Finding element present at the Xth index in the set
 
class custom_hash {
    public:
    static uint64_t splitmix64(uint64_t x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename T> using uset = unordered_set<T, custom_hash>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2> using hash = gp_hash_table<T1, T2, custom_hash>;
// FenwickTree
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll inv(ll i, ll m) {if (i == 1) return 1; return (m - ((m / i) * inv(m % i, m)) % m) % m;}
ll mod(ll x, ll m) {return ((x % m + m) % m);}   // Irrespective of x, whether it is +ve or -ve => we will get correct ans;
ll mod_add(ll a, ll b, ll m) {return mod((mod(a, m) + mod(b, m)), m);}
ll mod_sub(ll a, ll b, ll m) {return mod((mod(a, m) - mod(b, m)), m);}
ll mod_mul(ll a, ll b, ll m) {return mod((mod(a, m) * mod(b, m)), m);}
// mod_pow or expo
ll expo(ll a, ll b, ll m) { ll res = 1; while (b) { if (b & 1) { res = mod_mul(res, a, m); } a = mod_mul(a, a, m); b = b >> 1; } return res; } 
void swap(int &a, int &b) {a ^= b; b ^= a; a ^= b;}
ll pwr(ll a, ll b, ll mod) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
bool pow_of_2(ll n) { if(n != 0 && (n & n - 1) == 0) return true; return false; }
/*--------------------------------------------------------------------------------------------------------------------------*/
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1, 0);
    map<int, int> mpp;
    //CODE With Unordered Map + Custom hash
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        mpp[i] = arr[i];
    }
 
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        sum+=arr[i];
    }
    
    ll k = -1;
    while(q--) {
        ll type;
        cin >> type;
        if(type == 1) {
            ll x, y;
            cin >> x >> y;
            if(mpp[x]) {
                sum+=(y - mpp[x]);
                mpp[x] = y;
            }
            else {
                sum+=(y - k);
                mpp[x] = y;
            }
        }
        else {
            ll val;
            cin >> val;
            sum = n * 1LL * val;
            mpp.clear(); 
            k = val;           
        }
        cout << sum << endl;
    } 
 
}
 
int main() {
    fastio(); 
    int T = 1;
    // cin >> T;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(T--) {
        solve();
    }
 
    return 0;
}