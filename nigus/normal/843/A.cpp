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

vector<ll> A;
vector<ll> A2;

map<ll,ll> M;

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        A2.push_back(a);
    }
    sort(all(A2));

    for(ll c1 = 0; c1 < n; c1++){
        M[A2[c1]] = c1;
    }

    ll ans = 0;
    bool mark[200001] = {0};
    vector<vector<ll> > C(100002, vector<ll>());

    for(ll c1 = 0; c1 < n; c1++){
        if(mark[c1] == 0){
            mark[c1] = 1;
            ans++;
            C[ans-1].push_back(c1);
            ll i = M[A[c1]];
            while(i != c1){
                mark[i] = 1;
                C[ans-1].push_back(i);
                i = M[A[i]];
            }
        }
    }
    cout << ans << "\n";
    for(ll c1 =0 ; c1 < ans; c1++){
        cout << sz(C[c1]) << " ";
        for(ll c2 = 0; c2 < sz(C[c1]); c2++){
            cout << C[c1][c2]+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}