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

const int MAXN = 1000001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c1,0,T){
        cin >> n >> q;
        vi A, pref;
        pref.push_back(0);
        string s;
        cin >> s;
        rep(c1,0,n){
            a = (s[c1]=='+');
            a ^= (c1%2);
            if(a == 0){
                A.push_back(-1);
            }
            else{
                A.push_back(1);
            }
            pref.push_back(pref.back()+A.back());
        }

        rep(c1,0,q){
            cin >> a >> b;
            a--;
            b--;
            int sum = abs(pref[b+1]-pref[a]);
            if(sum == 0){
                cout << "0\n";
            }
            else{
                cout << (b-a)%2+1 << "\n";
            }
        }

    }

    return 0;
}