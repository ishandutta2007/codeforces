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

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 500001;

vi A,A2,B;
vl P,P2;
ll ans = 0;

bool subseq(){
    int i = 0;
    rep(c1,0,n){
        if(A[c1] == B[i])i++;
        if(i == m)return 1;
    }
    return 0;
}

map<int,int> M;

int belongs(ll x){
    if(x <= B[0])return 0;
    int l = 0;
    int r = m-1;
    while(l < r-1){
        int mid = (l+r)/2;
        if(x <= B[mid]){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}

ll W[MAXN] = {0};
ll penalty[MAXN] = {0};
ll DP[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A2.push_back(a);
    }
    rep(c1,0,n){
        cin >> a;
        P2.push_back(a);
    }
    cin >> m;
    rep(c1,0,m){
        cin >> a;
        M[a] = c1;
        B.push_back(a);
    }
    rep(c1,0,n){
        if(A2[c1] <= B.back()){
            A.push_back(A2[c1]);
            P.push_back(P2[c1]);
            if(P2[c1] < 0){
                ans += P2[c1];
            }
        }
        else{
            ans += P2[c1];
        }
    }

    n = sz(A);

    if(!subseq()){
        cout << "NO\n";
        return 0;
    }

    rep(c1,0,n){
        if(M.find(A[c1]) != M.end()){
            int i = M[A[c1]];
            penalty[c1] = W[i];
        }
        if(P[c1] > 0){
            int i = belongs(A[c1]);
            W[i] += P[c1];
        }
    }

    rep(c1,0,m){
        DP[c1] = big*big;
    }

    cout << "YES\n";
    for(int c1 = n-1; c1 >= 0; c1--){
        if(M.find(A[c1]) != M.end()){
            int i = M[A[c1]];
            ll w = penalty[c1];
            if(P[c1] < 0)w -= P[c1];
            ll temp = w + DP[i+1];
           // cerr << c1 << " - i=" << i << "   temp=" << temp << "\n";
            DP[i] = min(DP[i], temp);
        }
    }

    cout << DP[0]+ans << "\n";

    return 0;
}