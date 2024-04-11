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
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 501;

vl A;
vi kind;

ll DP[501][501] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> n;

    rep(c1,0,n){
        char ch;
        cin >> ch;
        if(ch == '+'){
            cin >> a;
            A.push_back(a);
            kind.push_back(1);
        }
        else{
            A.push_back(-1);
            kind.push_back(0);
        }
    }

    ll ans = 0;
    rep(c1,0,n){
        if(kind[c1] == 0)continue;
        rep(c2,0,n){
            if(kind[c2] != 0){
                if(A[c2] > A[c1] || (c2 > c1 && A[c2] == A[c1])){
                    kind[c2] = 2;
                }
                else{
                    kind[c2] = 1;
                }
            }
        }

        for(int i = n; i >= 0; i--){
            for(int smaller = 0; smaller < n; smaller++){
                if(i == n){
                    DP[i][smaller] = 1;
                    continue;
                }
                if(i == c1){
                    DP[i][smaller] = DP[i+1][smaller];
                    continue;
                }
                if(kind[i] == 0){
                    if(smaller > 0){
                        DP[i][smaller] = DP[i+1][smaller] + DP[i+1][smaller-1];
                    }
                    else{
                        DP[i][smaller] = (1 + (i < c1))*DP[i+1][smaller];
                    }
                }
                else{
                    if(kind[i] == 1){
                        DP[i][smaller] = DP[i+1][smaller] + DP[i+1][smaller+1];
                    }
                    else{
                        DP[i][smaller] = 2*DP[i+1][smaller];
                    }
                }
                DP[i][smaller] %= mod;
            }
        }

        ans += DP[0][0] * A[c1];
        ans %= mod;

    }
    cout << ans << "\n";


    return 0;
}