#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vi ind;
vl A;
vl W;

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        ind.push_back(c1);
    }
    rep(c1,0,n){
        cin >> a;
        W.push_back(a);
    }
    ind.push_back(n);
    W.push_back(0);
    A.push_back(big+big);

    sort(all(ind),comp);

    ll ans = 0;
    priority_queue<ll> pq;
    ll sum = 0;
    ll prev = A[ind[0]];

    for(int c1 = 0; c1 <= n; c1++){
        a = ind[c1];
        if(A[a] != prev){
            b = prev;
            while(b < A[a] && !pq.empty()){
                sum -= pq.top();
                ans += sum;
                pq.pop();
                b++;
            }
        }
        sum += W[a];
        pq.push(W[a]);
        prev = A[a];
    }
    cout << ans << "\n";

    return 0;
}