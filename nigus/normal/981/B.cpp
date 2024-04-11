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

ll n,m,q,p;
ll T;

unordered_map<ll,ll> M;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    ll ans = 0;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        M[a] = b;
        ans += b;
    }

    cin >> m;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        if(M.find(a) != M.end()){

            if(b > M[a])ans += b-M[a];

        }
        else{
            ans += b;
        }
    }
    cout << ans << "\n";

    return 0;
}