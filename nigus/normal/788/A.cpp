#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;

vector<ll> A;
vector<ll> B;

vector<ll> X;
vector<ll> Y;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n;



    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        if(c1 > 0){
            B.push_back(abs(A[c1]-A[c1-1]));
        }
    }
     ll mi = 1;
    for(ll c1 = 0; c1 < sz(B); c1++){
        X.push_back(B[c1]*mi);
        mi *= -1;
    }
    mi = 1;
    for(ll c1 = 1; c1 < sz(B); c1++){
        Y.push_back(B[c1]*mi);
        mi *= -1;
    }

    ll ans = -big*big;
    ll now = 0;
    for(ll c1 = 0; c1 < sz(X); c1++){
        now += X[c1];
        if(now < 0)now = 0;
        ans = max(now,ans);

    }
    now = 0;
    for(ll c1 = 0; c1 < sz(Y); c1++){
        now += Y[c1];
        if(now < 0)now = 0;
        ans = max(now,ans);
    }

    cout << ans << "\n";

    return 0;
}