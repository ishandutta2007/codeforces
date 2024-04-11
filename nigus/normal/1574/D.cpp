#pragma GCC optimize("O3")
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

const ll MAXN = 200004;


vector<ull> H;

vector<vl> C(MAXN, vl());

set<ull> bad;
set<ull> seen;

ull h(vi I){
    ull res = 0;
    rep(c1,0,n){
        res += ull(I[c1]+1) * H[c1];
    }
    return res;
}

ll sum(vi I){
    ll res = 0;
    rep(c1,0,n){
        res += C[c1][I[c1]];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        cin >> c;
        rep(c2,0,c){
            cin >> a;
            C[c1].push_back(a);
        }
        H.push_back(random2());
      //  cerr << H.back() << "\n";
    }

    cin >> m;

    rep(c1,0,m){
        vi I;
        rep(c2,0,n){
            cin >> a;
            a--;
            I.push_back(a);
        }
        bad.insert(h(I));
    }

    priority_queue<pair<ll, vi> > pq;

    vi I;
    rep(c1,0,n){
        I.push_back(sz(C[c1]) - 1);
    }
    pq.push({sum(I), I});

    ll ans = -1;

    while(!pq.empty()){
        vi J = pq.top().second;
        pq.pop();

        ll hj = h(J);
        ll sj = sum(J);
        if(seen.find(hj) == seen.end()){
            seen.insert(hj);
            if(bad.find(hj) == bad.end()){
                ans = sj;
                I = J;
                break;
            }
            rep(c1,0,n){
                if(J[c1] > 0){
                    J[c1]--;
                    ll sj2 = sum(J);
                    pq.push({sj2, J});
                    J[c1]++;
                }
            }
        }
    }

    trav(i, I){
        cout << i+1 << " ";
    }cout << "\n";

 //   cout << ans << "\n";


    return 0;
}