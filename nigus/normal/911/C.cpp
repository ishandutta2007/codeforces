#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;
const ll lim = 1000000;

bool mark[lim] = {0};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    vector<ll> A;
    for(ll c1 = 0; c1 < 3; c1++){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));

    for(ll c1 = 0; c1 < 3; c1++){
        for(ll c2 = 0; c2 < lim; c2++){
            if(!mark[c2]){

                for(ll c3 = c2; c3 < lim; c3 += A[c1]){
                    mark[c3] = 1;
                }
                break;
            }
        }
    }

    string ans = "YES\n";
    for(ll c1 = 0; c1 < lim ;c1++){
        if(!mark[c1])ans = "NO\n";
    }
    cout << ans;

    return 0;
}