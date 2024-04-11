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
 
const int MAXN = 300006;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    
    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vl A(n);
        rep(c1,0,n){
            cin >> A[c1];
        }
        sort(all(A));
        if(n%2 == 1){
             cout << "NO\n";
             continue;
        }
        vl B;
        rep(c1,0,n/2){
            B.push_back(A[c1]);
            B.push_back(A[c1+n/2]);
        }
        bool fail = 0;
        rep(c1,0,n){
            int i = (c1+n-1)%n;
            int j = (c1+1)%n;
            if(B[c1] > B[i] && B[c1] > B[j])continue;
            if(B[c1] < B[i] && B[c1] < B[j])continue;
            fail = 1;
        }
        if(fail){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            rep(c1,0,n){
                cout << B[c1] << " ";
            }
            cout << "\n";
        }
    }
    

    return 0;
}