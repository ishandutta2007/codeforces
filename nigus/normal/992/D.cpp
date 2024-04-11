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

ll n,m,k,q,T;

ull verybig = 2e18+1;

vl A;
ll ones[200001] = {0};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;


   cin >> n >> k;
   // n = 200000;
   // k = 100000;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
       // a = rand()+1;
       // if(c1 >= 1000 && n-c1 <= 1000)a = 1;
        A.push_back(a);
    }
    a = 0;
    for(int c1 = n-1; c1 >= 0; c1--){
        if(A[c1] != 1){a = 0;}
        else{a++;}
        ones[c1] = a;
    }

    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ull prod = 1;
        ull ksum = 0;
        ll c2 = c1;
        while(c2 < n){
            //cout << c2 << " " << prod << "\n";
           // if(2*prod > verybig && A[c2] != 1)break;
            if(A[c2] == 1){
                ll diff = prod-ksum;
                if(diff > 0 && diff%k == 0 && diff/k <= ones[c2])ans++;
                ksum += ones[c2]*k;
                c2 += ones[c2];
            }
            else{
                ksum += k*A[c2];
                ld logp = log2(prod);
                ld loga = log2(A[c2]);
              //  cerr << logp << " " << loga << "  -  " << ll(prod*A[c2]) << "\n";
                if(logp + loga >= 62.0)break;
                prod *= A[c2];
                if(ksum == prod)ans++;
                c2++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}