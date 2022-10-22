#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
ll n,m,k,T,q;

vl A;

vl CS2;
vl CS1;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    ll tot2 = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        tot2 += (a == 2);
    }

    CS1.push_back(0);
    CS2.push_back(0);
    for(int c1 = 0; c1 < n; c1++){
        CS1.push_back(CS1[c1] + (A[c1] == 1));
        CS2.push_back(CS2[c1] + (A[c1] == 2));
    }
    ll ans = 0;
     ans = max(tot2, n-tot2);

    for(int c1 = 0; c1 < n; c1++){
        ll n2 = 0;
        ll dp = 0;
        for(int c2 = c1; c2 < n; c2++){
            if(A[c2] == 1){
                dp++;
            }
            else{
                n2++;
                dp = max(dp,n2);
            }
            ans = max(ans, dp + CS1[c1] + CS2[n] - CS2[c2+1]);
        }
    }
    cout << ans << "\n";

    return 0;
}