#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

bool mark[MAXN] = {0};

vi A;

void get_next(){
    for(int c1 = 1; c1 < MAXN; c1++){
        if(!mark[c1]){
            for(int c2 = c1+1; c2 < MAXN; c2++){
                if(!mark[c2]){
                    if(!mark[(c1^c2)]){

                       // cout << c1 << " " << c2 << " " << (c1^c2) << " ";
                        A.push_back(c1);
                        A.push_back(c2);
                        A.push_back((c1^c2));
                        mark[c1] = 1;
                        mark[c2] = 1;
                        mark[(c1^c2)] = 1;
                        return;

                    }
                }
            }
        }
    }
}

ll magic[4] = {0,2,3,1};

ll solve(){
    ll mo = n%3;
    ll n2 = (n-1)/3;

    ll starter = 1;
    ll tot = 0;

    while(tot + starter <= n2){
        tot += starter;
        starter *= 4;
    }



    ll diff = n2-tot;
    ll pal = 2*starter;

 //   cerr << diff << " " << pal << "  -  " << n2 << "\n";

    ll a = diff;
    ll t = 1;
    while(a > 0){
        pal += magic[a%4]*t;
        t *= 4;
        a /= 4;
    }

    if(mo == 1)return diff + starter;
    if(mo == 2)return pal;
    return ((diff + starter)^pal);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
/*
    rep(c1,0,30000){
        get_next();
    }
    n= 13;
    solve();

    rep(c1,0,30000){
        n = c1+1;
        assert(A[c1] ==solve());
    }
*/
    /*
    ll prev = -1;
    rep(c1,0,sz(A)/3){
        cerr << c1 << ": " << A[c1*3] << " - " << (A[c1*3+1]) << " - " << (A[c1*3+2]) << "\n";
        if(A[c1*3] - prev != 1){
           // cerr << "HEJ " << prev << " " << A[c1*3] << "  at " << c1 << "\n";
        }

        prev = A[c1*3];
    }
*/

cin >> T;

    rep(c4,0,T){

    cin >> n;
/*
    ll a1 = solve();
    n = n+1;
    ll a2 = solve();
    n++;
    ll a3 = solve();

    cerr << (a1^a2 ^a3) << "\n";
*/
    ll ans = solve();
    cout << ans << "\n";
    }

    return 0;
}