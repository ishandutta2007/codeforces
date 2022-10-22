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
vl B;

bool check(int i){
    for(int c1 = 0; c1 < i; c1++){
        ll r = A[c1];
        for(int c2 = c1+i; c2 < n; c2+=i){
            if(A[c2] != r)return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    a = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> b;
        A.push_back(b-a);
        a=b;
    }

    for(int c1 = 1; c1 <= n; c1++){
        if(check(c1)){
            B.push_back(c1);
        }
    }

    cout << sz(B) << "\n";

    for(int c1 = 0; c1 < sz(B); c1++){
        cout << B[c1] << " ";
    }

    return 0;
}