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

ll n,m,T,k,d;
const ll big = 1000000007;

vl A;

unordered_map<ll,ll> M;
set<ll> S;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;
    ll ones = (1 << k)-1;
    ll xo = 0;
    M[xo] = 1;
    A.push_back(0);
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        xo ^= a;
        if(M.find(xo) == M.end()){
            M[xo] = 0;
        }
        M[xo]++;
        A.push_back(xo);
    }

    ll ans = 0;

    for(int c1 = 0; c1 < n+1; c1++){

        a = A[c1];
        if(S.find(a) == S.end()){
            ll sum = M[a];
            b = (ones ^ a);
            if(M.find(b) != M.end()){
                sum += M[b];
            }
            S.insert(a);
            S.insert(b);

            ll d1 = sum/2;
            ll d2 = sum/2+sum%2;

            ans += (d1*(d1-1))/2;
            ans += (d2*(d2-1))/2;

        }

    }

    ans = (n*(n+1))/2 - ans;
    cout << ans << "\n";
    return 0;
}