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
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 250001;

vl A;

vl negative, positive;

ll con,lin;

ll INF = big*big + 1337;

ll solve(vl pos, vl neg, ll zeros){
    rep(_,0,zeros){
        pos.push_back(0);
    }
    sort(all(pos));
    sort(all(neg));
    ll con = 0;
    ll lin = 0;

    ll P = pos.back();
    ll N = neg.back();

    trav(y, pos){
        con += -y*N;
        lin += (y-N);
    }
    rep(c1,0,sz(neg)-1){
        ll y =neg[c1];
        con += -y*P;
        lin += (P-y);
    }

    vl X;

    ll res = con;

    rep(c1,0,sz(neg)-1){
        ll y = neg[c1];

        ll oldc = -y*P;
        ll oldL = P-y;

        ll newc = y*N;
        ll newL = -N-y;

        ll div = (newc - oldc) / (oldL - newL);


        ll div2 = (newc - oldc + (oldL - newL - 1)) / (oldL - newL);



        res = max(res, con+div*lin);


        con -= oldc;
        con += newc;

        lin -= oldL;
        lin += newL;

        res = max(res, con+(div2)*lin);

    }


   // cerr << lin << "   heh\n";

    if(lin > 0)return INF;


    return res;
}

int main() {
   ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;



    rep(c4,0,T){
        cin >> n;
        A.clear();
        negative.clear();
        positive.clear();
        bool zero = 1;

        ll zeros = 0;

        rep(c1,0,n){
            cin >> a;
            if(a != 0)zero = 0;
            A.push_back(a);
            if(a < 0){
                negative.push_back(-a);
            }
            if(a > 0){
                positive.push_back(a);
            }
            if(a == 0)zeros++;
        }
        if(zero){
            cout << "0\n";
            continue;
        }

        sort(all(negative));
        sort(all(positive));

        if(sz(negative) == 0 || sz(positive) == 0){
            cout << "INF\n";
            continue;
        }

        ll ans1 = solve(positive, negative, zeros);
        ll ans2 = solve(negative, positive, zeros);

        ll ans = max(ans1, ans2);
        if(ans == INF){
            cout << "INF\n";
            continue;
        }

        cout << ans << "\n";

    }


    return 0;
}