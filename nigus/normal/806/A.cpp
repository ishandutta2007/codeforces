#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k;

ll mod(ll x, ll i){
if(x < 0)return mod(i-mod(-x,i),i);
return x % i;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    ll x,y,p,q;
    cin >> T;
    for(ll c4 = 0; c4 < T; c4++){
        cin >> x >> y >> p >> q;

        ll num = x*q - y*p;

        if((p == q && x != y) || (p == 0 && x != 0)){
            cout << "-1\n";
        }
        else{
            if(num == 0){
                cout << "0\n";
            }
            else{

                ll mo1 = mod(-x,p);
                ll mo2 = mod(-y,q);

                ll xp = (x+p-1)/p;
                ll yq = (y+q-1)/q;

                ll d = mo1-mo2 + p * (yq-xp);
                ll n = max((d+(q-p-1))/(q-p),0ll);
                n = max(n , xp-yq);

                ll i = mo1 + n*q;
                ll j = mo2 + n*p;

                ll nx = yq-xp + n;

                //cout << n << " " << nx << "\n";


                cout << n*q + mo2 << "\n";

            }
        }

    }

    return 0;
}