#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,q,T,k;

vector<ll> A;
vector<ll> B;
vector<ll> ind;

bool comp(ll i, ll j){
return A[i]-B[i] < A[j]-B[j];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c;

    cin >> n >> k;

    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
        ind.push_back(c1);
    }

    sort(ind.begin() , ind.end() , comp);

    ll ans = 0;

    for(c1 = 0; c1 < k; c1++){
        a = ind[c1];
        ans += A[a];
    }

    for(c1 = k; c1 < n; c1++){
        a = ind[c1];
        ans += min(A[a] , B[a]);
    }

    cout << ans << "\n";

    return 0;
}