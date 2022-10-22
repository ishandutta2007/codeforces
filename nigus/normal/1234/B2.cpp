#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
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
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;


    cin >> n >> k;
    queue<int> Q;
    set<int> S;

    int inq = 0;

    rep(c1,0,n){
        cin >> a;
        if(S.find(a) != S.end())continue;

        if(inq == k){
            b = Q.front();
            S.erase(b);
            Q.pop();
            inq--;
        }
        Q.push(a);
        S.insert(a);
        inq++;
    }
    vi ANS;
    while(!Q.empty()){
        ANS.push_back(Q.front());
        Q.pop();
    }
    reverse(all(ANS));
    cout << sz(ANS) << "\n";
    trav(y,ANS){
        cout << y << " ";
    }

    return 0;
}