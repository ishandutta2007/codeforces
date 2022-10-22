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

const int MAXN = 200101;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vl A;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }

        int a1 = 0;
        int a2 = n;
        int ans = 0;

        vector<ll> twos(n+1,0);
        int last[2] = {0};
        last[1] = -1;

        int sig = 0;

        rep(c1,0,n){
            if(A[c1] == 0){
                last[0] = c1+1;
                last[1] = -1;
                sig = 0;
            }
            else{
                if(A[c1] < 0){
                    sig ^= 1;
                }

                if(abs(A[c1]) == 2){twos[c1+1] = twos[c1]+1;}else{twos[c1+1] = twos[c1];}

             //   cerr << c1 << ": " << sig << "   -   " << last[sig] << "    -  " << twos[c1+1] << "\n";

                if(last[sig] != -1){
                    if(twos[c1+1] - twos[last[sig]] > ans){
                        ans = twos[c1+1] - twos[last[sig]];
                        a1 = last[sig];
                        a2 = n-c1-1;
                    }
                }

                if(last[sig] == -1)last[sig] = c1+1;
            }
        }
        cout << a1 << " " << a2 << "\n";

    }


    return 0;
}