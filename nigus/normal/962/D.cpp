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
ll n,k,m,d;

unordered_map<ll,ll> M;
vector<vl> C(200000, vl());
vl B;
ll now = 0;
vl A;
vl A2;
ll left2(ll i){
    ll i2 = i;
    while(i2%2 == 0)i2/=2;
    return i2;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
    //n = 150000;
    for(int c1 = 0 ;c1 < n; c1++){
        cin >> a;
       // a = 536870912;
        A.push_back(a);
        b = left2(a);
        if(M.find(b) == M.end()){
            M[b] = now;
            now++;
            B.push_back(b);
        }
        C[M[b]].push_back(c1);
    }

    for(int c1 = 0; c1 < now; c1++){
        ll t = B[c1];

        for(int c2 = 0; c2 < 60; c2++){

            ll prev1 = -1;
            ll prev2 = -1;

            for(int c3 = 0; c3 < sz(C[c1]); c3++){
                if(A[C[c1][c3]] == t){
                    prev1 = prev2;
                    prev2 = c3;

                   // cout << prev1 << " " << prev2 << "\n";

                    if(prev1 != -1){
                        A[C[c1][prev1]] = -1;
                        A[C[c1][prev2]] = 2*t;
                        prev1 = -1;
                        prev2 = -1;
                    }
                }
            }

            t *= 2;
            if(t > 1000000000000000000ll)break;
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] != -1)A2.push_back(A[c1]);
    }
    cout << sz(A2) << "\n";
    for(int c1 = 0; c1 < sz(A2); c1++){
        cout << A2[c1] << " ";
    }

    return 0;
}