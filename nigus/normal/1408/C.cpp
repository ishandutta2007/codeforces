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

const int MAXN = 300001;

ll l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){

        vi A;
        cin >> n >> l;
        A.push_back(0);
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        A.push_back(l);
        n += 2;
        vector<double> T1(n), T2(n);
        T1[0] = 0;
        ll speed = 1;
        rep(c1,1,n){
            T1[c1] = T1[c1-1] + double(A[c1] - A[c1-1]) / double(speed);
            speed++;
        }

        T2[n-1] = 0;
        speed = 1;
        for(int c2 = n-2; c2 >= 0; c2--){
            T2[c2] = T2[c2+1] + double(A[c2+1] - A[c2]) / double(speed);
            speed++;
        }

      /*  rep(c1,0,n){
            cout << T1[c1] << " " << T2[c1] << "  t1t2\n";
        }
*/
        for(int t = 0; t < n; t++){
            if(T2[t] < T1[t]){
                ll speed1 = t;
                ll speed2 = n-t;
                double t1 = T1[t-1];
                double t2 = T2[t];

                double m1 = A[t-1] - speed1 * t1;
                double m2 = A[t] + speed2 * t2;

                double x = (m2-m1) / double(speed1 + speed2);

                double y = double(speed1) * x + m1;

                cout << setprecision(18) << x << "\n";
                break;

            }
        }


    }

    return 0;
}