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

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

vl A,B,A2,B2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        if(c1>0)A2.push_back(a-A[c1-1]);
    }
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
        if(c1>0)B2.push_back(a-B[c1-1]);
    }
    if(A[0] != B[0] || A[n-1] != B[n-1]){
        cout << "No\n";
        return 0;
    }
    sort(all(A2));
    sort(all(B2));
    for(int c1 = 0; c1 < n-1; c1++){
        if(A2[c1] != B2[c1]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}