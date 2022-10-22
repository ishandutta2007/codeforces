#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll n,m,T,k,q;


const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

ll dist[100001] = {0};
ll latest[100001] = {0};
ll early[100001] = {0};
vi B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> k;

    for(int c1 = 0; c1 < n; c1++){
        latest[c1] = -1;
        early[c1] = -1;
    }

    for(int c1 = 0; c1 < k; c1++){
        cin >> a;
        a--;
        B.push_back(a);
        if(c1 > 0)dist[c1] = dist[c1-1];
        if(latest[a] == -1){
            dist[c1]++;
            early[a] = c1;
        }
        latest[a] = c1;
    }
    ll ans = (n-dist[k-1]);

    for(int c1 = 0; c1 < n-1; c1++){
        if(early[c1] == -1 || early[c1+1] == -1)ans += 2;
    }

    for(int c1 = k-1; c1 >= 0; c1--){
        a = B[c1];
        if(latest[a] == c1){
            if(a > 0){
                b = a-1;
                if(early[b] > c1){
                    //cerr << a << " " << b << " " << early[b] << "\n";
                    ans++;
                }
            }
            if(a < n-1){
                b = a+1;
                if(early[b] > c1){
                   // cerr << a << " " << b << " " << early[b] << "\n";
                    ans++;
                }
            }

        }
    }

    cout << ans << "\n";

    return 0;
}