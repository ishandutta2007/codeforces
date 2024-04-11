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

vi A, A2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        A2.push_back(a);
    }
    if(n == 1){
        cout << (A[0]+1)/2 << "\n";
        return 0;
    }
    ll ans = 12798172811;
    sort(all(A2));
    ans = (A2[0]+1)/2 + (A2[1]+1)/2;

    rep(c1,0,n-1){
        a = A[c1];
        b = A[c1+1];
        if(a > b)swap(a,b);
        ll temp = 12891281911111;
        if(2*a <= b){
            temp = (b+1)/2;
            ans = min(ans, temp);
        }
        else{
            c = b-a;
            a -= c;
            b -= 2*c;
            temp = c;

            ll t3 = a / 3;
            temp += 2*t3;

            temp += a%3;
            //if(a%3 == 1 && a > 1)temp--;

            ans = min(ans, temp);

        }
    }

    rep(c1,0,n-2){
        ll temp = min(A[c1], A[c1+2]);
        c = max(A[c1], A[c1+2]) - min(A[c1], A[c1+2]);
        temp += (c+1)/2;
        ans = min(ans, temp);
    }

    cout << ans << "\n";

    return 0;
}