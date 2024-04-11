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

const ll MAXN = 200006;

vi A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;
    
    cin >> T;

    rep(c4,0,T){
        cin >> n;
        A.clear();
        int zeros = 0;
        rep(c1,0,n){
            cin >> a;
            zeros += (a == 0);
            if(a != 0){
                A.push_back(a);
            }
        }
        sort(all(A));

        rep(_,0,n-1){
            vi B;

            if(sz(A) == 0){
                A.push_back(0);
                break;
            }

            if(zeros > 0){
                B.push_back(A[0]);
                zeros--;
            }

            rep(c1,0,sz(A)-1){
                B.push_back(A[c1+1]-A[c1]);
            }
            sort(all(B));
            A.clear();
            trav(b, B){
                if(b == 0){
                    zeros++;
                }
                else{
                    A.push_back(b);
                }
            }
           
            if(sz(A) == 0){
                A.push_back(0);
                break;
            }
            

        }
        cout << A[0] << "\n";

    }

    return 0;
}