#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,p;
ll T;

vl A;
unordered_map<ll,ll> M;

bool dp(ll i, ll k2, ll mask){
    if(i == n)return 1;
    ll h = 50*50*mask+50*i+k2;
    if(M.find(h) != M.end())return M[h];


    bool ans = 0;
    ll sum = 0;
    for(ll c1 = i; c1 < n-k2+1; c1++){
        sum += A[c1];
        if(k2 == 1 && c1 < n-1)continue;
        if((sum & mask) == mask){
            ans |= dp(c1+1,k2-1,mask);
        }
    }
    M[h] = ans;
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> k;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }


    ll ans = 0;
    for(ll c1 = 60; c1 >= 0; c1--){

       // cout << (1ll << c1) << "\n";

        bool test = dp(0,k,(ans+(1ll << c1)));
        if(test)ans += (1ll << c1);

    }
    cout << ans << "\n";
    return 0;
}