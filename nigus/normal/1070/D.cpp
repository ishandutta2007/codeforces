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

vl A,B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> k;
    for(int c1 = 0; c1 < n ;c1++){
        cin >> a;
        A.push_back(a);
        B.push_back(a);
    }
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(c1 == n-1){
            ans += (A[c1]+k-1)/k;
        }
        else{
            ll rid = A[c1]%k;
            if(rid > B[c1]){
                ans += (A[c1]+k-1)/k;
            }
            else{
                A[c1+1]+=rid;
                ans += A[c1]/k;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}