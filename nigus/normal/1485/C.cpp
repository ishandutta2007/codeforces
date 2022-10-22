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

ll solve(){
    ll b = 1;
    ll ans = 0;
    while(1){
        ll far = (b+1)*(b-1);
        if(far <= n){
            ans += b-1;
            b++;
            if(b > m)break;
        }
        else{

            ll look = n/(b+1);
            ll l = b;
            ll r = m+1;
            while(l < r-1){
                ll mid = (l+r)/2;
                if(n/(mid+1) < look){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            ans += look * (l-b+1);
            b = l+1;
            if(b > m)break;

        }
    }
    return ans;
}

ll NUM[MAXN] = {0};
ll NUM2[MAXN] = {0};

ll DIV[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;

    rep(c4,0,T){

        a = 0;

        cin >> n >> m;
/*
        rep(c1,1,n+1){
            rep(c2,1,m+1){
                if(c1/c2 == c1%c2){
                  //  cerr << c1 << " " << c2 << "  \n";
                    NUM[c1]++;
                    NUM2[c2]++;
                    a++;
                }
                if(c1%c2 == 0){
                    DIV[c1]++;
                }
            }
        }

        cerr << a << "\n";*/
        cout << solve() << "\n";

    }

    return 0;
}