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

const int MAXN = 200001;

vector<pii> A, B;
vi AI, BI;
vector<bool> seen;
vi Q;

void add_q(int i){
    if(seen[i])return;
    seen[i] = 1;
    Q.push_back(i);
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
        B.clear();
        AI.clear();
        BI.clear();
        seen.clear();
        Q.clear();

        rep(c1,0,n){
            cin >> a;
            A.push_back({a, c1});
            seen.push_back(0);
            AI.push_back(0);
            BI.push_back(0);
        }
        rep(c1,0,n){
            cin >> a;
            B.push_back({a, c1});
        }
        sort(all(A));
        sort(all(B));

        rep(c1,0,n){
            AI[A[c1].second] = c1;
            BI[B[c1].second] = c1;
        }

        add_q(A.back().second);
        add_q(B.back().second);

        int p1 = n-1;
        int p2 = n-1;

        while(sz(Q) > 0){
            int i = Q.back();
            Q.pop_back();

            rep(c1,AI[i],p1){
                add_q(A[c1].second);
            }
            rep(c1,BI[i],p2){
                add_q(B[c1].second);
            }
            p1 = min(p1, AI[i]);
            p2 = min(p2, BI[i]);

        }


        rep(c1,0,n){
            cout << seen[c1];
        }cout << "\n";


    }

    return 0;
}