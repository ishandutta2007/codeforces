#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,h,T;

vector<ll> A;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    ll g = -1;
    ll n1 = 0;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        if(c1 == 0){
            g = a;
        }
        else{
            g = gcd(g,a);
        }
        if(a != 1)n1++;
        A.push_back(a);
    }

    if(g != 1){
        cout << "-1\n";
    }
    else{
        if(n1 != n){
            cout << n1 << "\n";
        }
        else{
            ll l = n;
            for(ll c1 = 0; c1 < n; c1++){
                ll g2 = A[c1];
                for(ll c2 = c1-1; c2 >= 0; c2--){
                    g2 = gcd(g2,A[c2]);
                    if(g2 == 1){
                        l = min(l,c1-c2-1);
                        break;
                    }
                }
            }
            cout << n+l << "\n";
        }
    }

    return 0;
}