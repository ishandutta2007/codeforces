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
 
const int MAXN = 200006;
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vl A;
        vector<pii> P;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        vl B;
        rep(c1,0,n){
            cin >> a;
            B.push_back(a);
        }
        rep(c1,0,n){
            P.push_back({A[c1], B[c1]});
        }
        sort(all(A));
        sort(all(B));
        vector<pii> ANS;
        bool fail = 0;


        rep(c1,0,n){
            a = A[c1];
            b = B[c1];
            if(P[c1].first == a && P[c1].second == b)continue;
            int i = -1;
            rep(c2,c1+1,n){
                if(P[c2].first == a && P[c2].second == b){
                    i = c2;
                    break;
                }
            }
            if(i == -1){
                fail = 1;
                break;
            }
            ANS.push_back({c1+1,i+1});
            swap(P[c1], P[i]);
        }
        if(fail){
            cout << "-1\n";
        }
        else{
            cout << sz(ANS) << "\n";
            trav(p ,ANS){
                cout << p.first << " " << p.second << "\n";
            }
        }
        
    }
 
    return 0;
}