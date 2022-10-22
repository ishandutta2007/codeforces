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

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,x;

ll DP[12][1025][66][2] = {0};

vector<ll> A;

ll dp(ll base, ll mask, ll left, ll lz){
    if(left == 0)return (mask == 0);
    if(DP[base][mask][left][lz] != -1)return DP[base][mask][left][lz];
    ll t = 1;
    ll ans = 0;
    for(ll c1 = 0; c1 < base; c1++){
        ll lz2 = 0;
        ll mask2 = mask^t;
        if(lz == 1 && c1 == 0){
            mask2 = mask;
            lz2 = 1;
        }
        ans += dp(base, mask2, left-1, lz2);
        t *= 2;
    }
   // cout << "base: " << base <<"   mask:  " << mask << "   left: " << left << " lz: " << lz << "     ans: " << ans << "\n";
    DP[base][mask][left][lz] = ans;
    return ans;
}

ll f(ll r, ll base){
    if(r == 0)return 1;
    A.clear();
    ll r2 = r;
    while(r2 > 0){
        A.push_back(r2%base);
        r2 /= base;
    }
    reverse(all(A));
    ll mask = 0;
    ll ans = 0;
    for(ll c1 = 0; c1 < sz(A); c1++){
        for(ll c2 = 0; c2 < A[c1]; c2++){
            ll mask2 = mask^(1 << c2);
            ll lz = 0;
            if(c1 == 0 && c2 == 0){
                lz = 1;
                mask2 = mask;
            }
            ans += dp(base, mask2, sz(A)-c1-1, lz);
        }
        mask ^= (1 << A[c1]);
    }
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

        for(ll c1 = 0; c1 < 12; c1++){
            for(ll c2 = 0; c2 < 1025; c2++){
                for(ll c3 = 0; c3 < 66; c3++){
                    for(ll c4 = 0; c4 < 2; c4++){
                        DP[c1][c2][c3][c4] = -1;
                    }
                }
            }
        }
    cin >> q;
    for(ll c1 = 0; c1 < q; c1++){
        cin >> a >> b >> c;
        ll a1 = f(c+1,a);
        ll a2 = f(b,a);
        cout << a1-a2 << "\n";
    }

    return 0;
}