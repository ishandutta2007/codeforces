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



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> a >> b;
        if(a+b > n-2 || abs(a-b) > 1){
            cout << "-1\n";
        }
        else{
            int L = 0;
            int R = n-1;
            vi A;
            bool par = 0;
            if(b > a)par = 1;
            rep(c1,0,a+b+1){
                if(par){
                    A.push_back(R+1);
                    R--;
                }
                else{
                    A.push_back(L+1);
                    L++;
                }
                par ^= 1;
            }
            if(!par){
                for(int c1 = R; c1 >= L; c1--){
                    A.push_back(c1+1);
                }
            }
            else{
                for(int c1 = L; c1 <= R; c1++){
                    A.push_back(c1+1);
                }
            }

            rep(c1,0,n){
                cout << A[c1] << " ";
            }cout << "\n";
        }
    }

    return 0;
}