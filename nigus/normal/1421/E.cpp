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

vector<vector<vi> > C(10, vector<vi>());

 vl A,B;

bool evil(){
    if(n%2 == 0)return 0;
    ll mi = big;
    ll ma = -big;
    rep(c1,0,n){
        if(c1%2 == 0)mi = min(mi, A[c1]);
        if(c1%2 == 1)ma = max(ma, A[c1]);
    }
    if(mi > ma)return 1;
    return 0;
}

ll solve_evil(){
    ll mi = big;
    ll ma = -big;
    ll sum_a = 0;
    ll sum_b = 0;
    rep(c1,0,n){
        if(c1%2 == 0){mi = min(mi, A[c1]); sum_a += A[c1];}
        if(c1%2 == 1){ma = max(ma, A[c1]); sum_b += A[c1];}
    }
    return sum_a - sum_b - 2*mi + 2*ma;
 }

 ll solve(ll pos){
    ll res = 0;

    if(pos-1 == n/2 && evil()){
        return solve_evil();
    }

    for(int c1 = 0; c1 < n; c1++){
        if(c1 < pos){
            res += B[c1];
        }
        else{
            res -= B[c1];
        }
    }
    return res;
 }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;
    /*
    const int lim = 10;

    C[1].push_back({1});
    rep(c1,2,lim){
        rep(c2,1,c1){
            vi temp;
            trav(v1, C[c2]){
                trav(v2, C[c1-c2]){
                    vi temp;
                    trav(y, v1){
                        temp.push_back(-y);
                    }
                    trav(y, v2){
                        temp.push_back(-y);
                    }
                    C[c1].push_back(temp);
                }
            }
        }
    }

    rep(c1,1,lim){
        cerr << "\n------------ " << c1 << "----------------\n";
        trav(v, C[c1]){
            trav(y, v){
                cerr << (y+1)/2 << "";
            }cerr << "\n";
        }
    }
    */


    cin >> n;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        B.push_back(a);
    }

    if(n == 1){
        cout << A[0] << "\n";
        return 0;
    }

    if(n == 2){
        cout << -(A[0] + A[1]) << "\n";
        return 0;
    }



    ll mii = 0;
    rep(c1,0,n){
        if(A[c1] > 0)mii++;
    }
    sort(all(B));
    reverse(all(B));

    int start = 2-n%3;
    ll ans = -big*big;
    for(int c1 = start; c1 <= n; c1 += 3){
        if(abs(c1 - mii) <= 30){
            ll temp = solve(c1);
            ans = max(temp, ans);
        }
    }

    cout << ans << "\n";

    return 0;
}