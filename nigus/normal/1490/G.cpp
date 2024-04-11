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

const int MAXN = 200001;

vl A, ind;

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> T;

    rep(c4,0,T){
        cin >> n >> q;
        vl A, CS, I;
        ll sum = 0;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            sum += a;
            if(c1 == 0 || sum > CS.back()){
                CS.push_back(sum);
                I.push_back(c1);
            }
        }
        rep(c1,0,q){
            cin >> a;
            if(a > CS.back() && sum <= 0){
                cout << "-1 ";
                continue;
            }
            ll diff = max(0ll,a-CS.back());
            ll laps;
            if(sum <= 0){laps = 0;}
            else{laps = (diff+sum-1)/sum;}
            if(sum < 0)laps = 0;
            ll ans = laps*n;
            a -= laps*sum;

            int L = 0;
            int R = sz(CS);
            while(L < R-1){
                int mid = (L+R)/2;
                if(CS[mid] < a){
                    L = mid;
                }
                else{
                    R = mid;
                }
            }
            if(CS[0] >= a)R = 0;
            ans += I[R];
            cout << ans << " ";
        }cout << "\n";
    }

    return 0;
}