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
ll n,m,T,k,q,p,x;

ll best, bx;
ll lim1 = 999;

vector<ll> ind;

ll nq = 0;

pair<ll,ll> ask(ll i){
    ll j1,j2;
    nq++;
    cout << "? " << i+1 << "\n";
    fflush(stdout);
    cin >> j1 >> j2;
    /*
    if(j1 == -1 && j2 == -1){
        exit(0);
    }*/

    assert(nq <= 1999);
    return {j1,j2-1};
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    bx = -1;

    cin >> n >> q >> x;
    q--;
    best = q;
    for(ll c1 = 0; c1 < n; c1++){
        ind.push_back(c1);
    }

    for(ll c2 = 0; c2 < 123; c2++){
        random_shuffle(all(ind));
    }

    for(ll c1 = 0; c1 < min(lim1,n); c1++){
        pair<ll,ll> pa = ask(ind[c1]);
        if(pa.first >= bx && pa.first < x){
            bx = pa.first;
            best = ind[c1];
        }
    }
    ll i = best;

    while(1){
        pair<ll,ll> pa = ask(i);
        if(pa.first >= x){
            cout << "! " << pa.first << "\n";
            fflush(stdout);
            break;
        }
        i = pa.second;
        if(i == -2){
            cout << "! " << -1 << "\n";
            fflush(stdout);
            break;
        }
    }

    return 0;
}