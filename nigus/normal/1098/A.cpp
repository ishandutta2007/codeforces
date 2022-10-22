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

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

vector<vl> C(100001, vl());
ll parent[100001] = {0};
ll B[100001] = {0};
ll A[100001] = {0};

ll H[100001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
    H[0] = 0;
    parent[0] = -1;
    for(int c1 = 0; c1 < n-1; c1++){
        cin >> a;
        a--;
        parent[c1+1] = a;
        C[a].push_back(c1+1);
        H[c1+1] = H[a]+1;
    }
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        B[c1] = a;
    }
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(B[c1] == -1){
            if(sz(C[c1]) == 0){
                B[c1] =  B[parent[c1]];
            }
            else{
                ll mib = big*big;
                for(int c2 = 0; c2 < sz(C[c1]); c2++){
                    mib = min(mib, B[C[c1][c2]]);
                }
                B[c1] = mib;
            }
        }
        if(c1 == 0){
            a = B[c1];
        }
        else{
            a = B[c1]-B[parent[c1]];
        }

        if(a < 0){
            cout << -1 << "\n";
            return 0;
        }
        ans += a;
    }
    cout << ans << "\n";
    return 0;
}