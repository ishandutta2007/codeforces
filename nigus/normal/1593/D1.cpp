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

const ll MAXN = 1000004;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vi A;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        sort(all(A));
        if(A[0] == A[n-1]){
            cout << "-1\n";
            continue;
        }
        int d = abs(A[0] - A[n-1]);

        vi divs;
        for(int c1 = 1; c1*c1 <= d; c1++){
            if(d%c1 == 0){
                divs.push_back(c1);
                if(c1*c1 != d){
                    divs.push_back(d/c1);
                }
            }
        }

        sort(all(divs));
        int ans = -2;
        for(int c1 = sz(divs)-1; c1 >= 0; c1--){
            d = divs[c1];

            bool yes = 1;
            for(int c2 = 0; c2 < n; c2++){

                //cerr << A[c2]%d << " - " << A[0]%d << "  -  " << d << "  fd\n";

                int mo1 = (d-A[c2]%d)%d;
                int mo2 = (d-A[0]%d)%d;

                if(mo1 != mo2){
                    yes = 0;
                    break;
                }
            }
            if(yes){
                ans = d;
                break;
            }
        }

        cout << ans << "\n";

    }


    return 0;
}