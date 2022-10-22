#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q;

ll F[26] = {0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    if(n < 3){
        cout << "No\n";
    }
    else{

        if(n%2 == 1){
            cout << "Yes\n";
            cout << "1 " << n << "\n";
            cout << n-1 << " ";
            for(int c1 = 0; c1 < n-1; c1++){
                cout << c1+1 << " ";
            }
            cout << "\n";
        }
        else{
            cout << "Yes\n";
            cout << "2 " << 1 << " " << n << "\n";
            cout << n-2 << " ";
            for(int c1 = 1; c1 < n-1; c1++){
                cout << c1+1 << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}