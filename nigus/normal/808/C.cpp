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
vector<ll> B;
vector<ll> ind;


bool comp(ll i, ll j){
return A[i] < A[j];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n >> m;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        ll a2 = a/2;
        m -= (a-a2);
        A.push_back(a);
        B.push_back(a-a2);
        ind.push_back(c1);
    }
    sort(all(ind),comp);
    if(m < 0){
        cout << "-1\n";
    }
    else{
        for(ll c1 = n-1; c1 >= 0; c1--){
            a = ind[c1];
            ll diff = min(m,A[a]-B[a]);
            m -= diff;
            B[a] += diff;
        }
        if(m != 0){
            cout << "-1\n";
        }
        else{
            for(ll c1 = 0; c1 < n; c1++){
                cout << B[c1] << " ";
            }
        }
    }
    return 0;
}