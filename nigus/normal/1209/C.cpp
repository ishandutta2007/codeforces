#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 200001;

vi A;
vi col;

bool test(){
    vi temp;
    rep(c1,0,n){
        if(col[c1] == 1){
            temp.push_back(A[c1]);
        }
    }
    rep(c1,0,n){
        if(col[c1] == 2){
            temp.push_back(A[c1]);
        }
    }


    rep(c1,0,n-1){
        if(temp[c1] > temp[c1+1])return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        string s;
        cin >> n;
        cin >> s;
        A.clear();
        col.clear();
        rep(c1,0,n){
            A.push_back(s[c1]-'0');
            col.push_back(2);
        }
        bool fail = 1;
        rep(c1,0,10){
            int ma = 0;
            rep(c2,0,n){
                if(A[c2] < c1 || (A[c2] == c1 && ma > c1)){
                    col[c2] = 1;
                }
                else{
                    col[c2] = 2;
                }
                ma = max(ma,A[c2]);
            }
            if(test()){
                fail = 0;
                break;
            }
        }
        if(fail){
            cout << "-\n";
        }
        else{
            rep(c1,0,n){
                cout << col[c1];
            }cout << "\n";
        }
    }

    return 0;
}