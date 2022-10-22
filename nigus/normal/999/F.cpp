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

ll n,m,k,q,T;

ll H[11] = {0};
ll fav[501] = {0};
set<ll> S;
vl faves;

ll FAV[100001] = {0};
ll F[100001] = {0};

bool DPC[501][5001] = {0};
ll DP[501][5001] = {0};

ll dp(ll people, ll cards){
    if(people == 0 || cards == 0)return 0;
    if(DPC[people][cards])return DP[people][cards];
    ll ans = 0;
    for(int c1 = 0; c1 <= min(k,cards); c1++){
        ll temp = H[c1] + dp(people-1,cards-c1);
        ans = max(ans, temp);
    }
    DPC[people][cards] = 1;
    DP[people][cards] = ans;
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> k;
    for(int c1 = 0; c1 < n*k; c1++){
        cin >> a;
        F[a]++;
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        if(S.find(a) == S.end()){
            S.insert(a);
            faves.push_back(a);
        }
        FAV[a]++;
    }

    for(int c1 = 0; c1 < k; c1++){
        cin >> a;
        H[c1+1] = a;
    }

    ll ans = 0;
    for(int c1 = 0; c1 < sz(faves); c1++){
        a = faves[c1];
        ans += dp(FAV[a], min(k*FAV[a],F[a]));
    }
    cout << ans << "\n";
    return 0;
}