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


uniform_int_distribution<> DD(0, (1ll << 31));

ll random(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 300001;

vl A;
vl B;
vl ind;

vl D;

vl negative;

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        ind.push_back(c1);
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> b;
        B.push_back(b);
    }
    sort(all(ind),comp);
    sort(all(B));

    ll tot = 0;

    for(int c1 = 0; c1 < n; c1++){
        D.push_back(B[c1] - A[ind[c1]]);
        if(D[c1] < 0){
            negative.push_back(c1);
        }
        tot += D[c1];
    }
    if(tot != 0){
        cout << "NO\n";
        return 0;
    }

    vector<vl> ANS;

    ll N = 0;
    bool fail = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(D[c1] < 0){
            fail = 1;
            break;
        }
        if(D[c1] > 0){
            if(N >= sz(negative)){
                fail = 1;
                break;
            }

            while(D[c1] > -D[negative[N]]){
                ANS.push_back({ind[c1], ind[negative[N]], -D[negative[N]]});
                D[c1] += D[negative[N]];
                D[negative[N]] = 0;
                N++;
                if(N >= sz(negative))break;
            }

            if(N >= sz(negative)){
                fail = 1;
                break;
            }

            ANS.push_back({ind[c1], ind[negative[N]], D[c1]});
            D[negative[N]] += D[c1];
            D[c1] = 0;
            if(D[negative[N]] == 0){
                N++;
            }
        }
    }

    if(!fail){
        cout << "YES\n" << sz(ANS) << "\n";
        for(int c1 = 0; c1 < sz(ANS); c1++){
            cout << ANS[c1][0]+1 << " " << ANS[c1][1]+1 << " " << ANS[c1][2] << "\n";
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
}