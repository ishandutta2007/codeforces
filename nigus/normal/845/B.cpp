#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q,p;

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    vector<ll> A;
    vector<ll> B;
    ll sa = 0;
    ll sb = 0;
    string s;
    cin >> s;
    for(ll c1 = 0; c1 < 6; c1++){
        A.push_back(ll(s[c1]) - ll('0'));
        sa += A[c1];
    }
    for(ll c1 = 3; c1 < 6; c1++){
        B.push_back(ll(s[c1]) - ll('0'));
        sb += B[c1-3];
    }
int ans = 1200;
    for(ll c1 = 0; c1 < 1000; c1++){
        for(ll c2 = 0; c2 < 1000; c2++){
            ll s1 = c1%10 + (c1/10)%10 + (c1/100)%10;
            ll s2 = c2%10 + (c2/10)%10 + (c2/100)%10;
            if(s1 == s2){
                   // cout << s1 << " " << s2 << "\n";
                ans = min(ans,(A[0] != c1%10) + (A[1] != (c1/10)%10) + (A[2] != (c1/100)%10) +
                          (B[0] != c2%10) + (B[1] != (c2/10)%10) + (B[2] != (c2/100)%10));
            }
        }
    }
    cout << ans << "\n";


    return 0;
}