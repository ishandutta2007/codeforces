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

ll n,m,k,q,p;
ll T;

vl A;
vl B;

ll modm(ll i){
    if(i < 0)return (m-modm(-i))%m;
    return i%m;
}

ll dist(ll i, ll j){
    return min(modm(i-j),modm(j-i));
}

bool between(ll i, ll l, ll r){
    return (dist(l,r) == dist(i,l) + dist(i,r));
}

vl X;
vl W;

vl starts;
vl B2;
vl I;
vl CS;

vl dumb;

bool solve(ll x){
    starts.clear();
    B2.clear();
    X.clear();
    W.clear();
    I.clear();
    CS.clear();
    for(int c1 = 0; c1 < n; c1++){
        starts.push_back(A[c1]);
    }
    for(int c1 = 0; c1 < n; c1++){
        starts.push_back(A[c1]+m);
    }
    for(int c1 = 0; c1 < n; c1++){
        starts.push_back(A[c1]+2*m);
    }

    for(int c1 = 0; c1 < n; c1++){
        B2.push_back((B[c1]+x)%(3*m));
    }
    for(int c1 = 0; c1 < n; c1++){
        B2.push_back((B[c1]+x+m)%(3*m));
    }
    for(int c1 = 0; c1 < n; c1++){
        B2.push_back((B[c1]+x+2*m)%(3*m));
    }

    starts.push_back(big*big);
    B2.push_back(big*big);

    ll l = 0;
    ll r = 0;

    ll r2 = 0;
    ll mib = big*big;
    for(int c1 = 0; c1 < 3*n; c1++){
        if(B2[c1] < mib){
            mib = B2[c1];
            r2 = c1;
        }
    }

    while(l+r < 6*n){

        if(starts[l] <= B2[r2]){
            X.push_back(1);
            W.push_back(starts[l]);
            I.push_back(l%n);
            l++;
        }
        else{
            X.push_back(-1);
            W.push_back(B2[r2]);
            I.push_back(-1);
            r++;
            r2++;
            r2 %= (3*n);
        }
    }

    CS.push_back(0);
    for(int c1 = 0; c1 < 6*n; c1++){
        ll y = X[c1];
        if(y > 0)y = 0;
        CS.push_back(CS[c1]+y);
       // cout << X[c1] << " ";
    }
   // cout <<"    " << x << "\n";

    ll sum = 0;
    for(int c1 = 0; c1 < 6*n; c1++){
        if(W[c1] > A[n-1]+m)break;
        if(sum < 0)sum = 0;
        if(X[c1] > 0){

            ll l2 = c1;
            ll r2 = 6*n;
            while(l2<r2-1){
                ll mid = (l2+r2)/2;
                if(W[mid] <= 2*x+W[c1]){
                    l2 = mid;
                }
                else{
                    r2 = mid;
                }
            }

            //cout << I[c1] << "  tot: " << CS[l2+1]-CS[c1] + sum + 1 << " sum: " << sum << " ";

            //cout << "x: " << x << "\n";

            ll sum2 = sum + CS[l2+1]-CS[c1] + 1;

            if(sum2 > 0)return 0;

        }

        sum += X[c1];
    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
    }

    sort(all(A));
    sort(all(B));

    ll l = -1;
    ll r = m/2;
    while(l < r-1){
        ll mid = (l+r)/2;
        bool test;
        test = solve(mid);
        if(test){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << r << "\n";

    return 0;
}