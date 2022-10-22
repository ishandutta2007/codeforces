#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return DD(eng)%r;
}

ll n,m,T,k,q;

vl B = {14,9,24,19};

bool gra(ll x){
    q++;
    cout << "> " << x << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    assert(res != -1);
    return res;
}

ll query(ll i){
    q++;
    cout << "? " << i << "\n";
    fflush(stdout);
    ll res;
    cin >> res;
    assert(res != -1);
    //res = B[i-1];
    return res;
}

void answer(ll mi, ll d){
    q++;
    cout << "! " << mi << " " << d << "\n";
    fflush(stdout);
}

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

vl A;
vl D;

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    q = 0;
    cin >> n;

    ll l = -1;
    ll r = 1000000000;
    while(l < r-1){
        ll mid = (l+r)/2;
        bool yes = gra(mid);
        if(yes){
            l =mid;
        }
        else{
            r = mid;
        }
    }

    ll ma = r;
    ll lim = 59-q;
   // cerr << q << "\n";
    for(int c1 = 0; c1 < lim; c1++){
        ll r = random(n);
        A.push_back(query(r+1));
    }
  //  cerr << q << "\n";
    for(int c1 = 0; c1 < sz(A); c1++){
        for(int c2 = c1+1; c2 < sz(A); c2++){
            if(A[c1] != A[c2])D.push_back(abs(A[c1]-A[c2]));
        }
    }

    ll g = 1;
    for(int c1 = 0; c1 < sz(D); c1++){
        if(c1 == 0){
            g = D[c1];
        }
        else{
            g = gcd(g, D[c1]);
        }
    }

    answer(ma-g*(n-1), g);

    return 0;
}