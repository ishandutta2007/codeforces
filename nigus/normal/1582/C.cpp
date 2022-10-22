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

const int MAXN = 300001;

string s;

ll rem(int c){
    int i = 0;
    int j = n-1;
    int res = 0;
    while(i < j){
        int a = s[i]-'a';
        int b = s[j]-'a';
        if(a != b){
            if(a != c && b != c)return big;
            if(a == c){
                res++;
                i++;
            }
            if(b == c){
                res++;
                j--;
            }
        }
        else{
            i++;
            j--;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        cin >> s;
        ll ans = big;
        for(int c1 = 0; c1 < 26; c1++){
            ans = min(ans, rem(c1));
        }
        if(ans == big){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }


    return 0;
}