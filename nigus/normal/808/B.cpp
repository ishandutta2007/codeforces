#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef  long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k;

vector<ll> A;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;
    cin >> n >> k;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    ll sum2 = 0;
    ll sum = 0;
    for(ll c1 = 0; c1 < k; c1++){
        sum2 += A[c1];
    }
    sum += sum2;

    for(ll c1 = k; c1 < n; c1++){
        sum2 -= A[c1-k];
        sum2 += A[c1];
        sum += sum2;
    }

    cout << setprecision(18) << ld(sum)/ld(n-k+1) << "\n";

    return 0;
}