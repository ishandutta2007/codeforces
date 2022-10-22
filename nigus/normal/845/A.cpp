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

    cin >> n;
    vector<ll> A;
    for(ll c1 = 0; c1 < 2*n; c1++){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));

    if(A[n-1] != A[n]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}