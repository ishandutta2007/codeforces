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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> n >> k;
        vi A(n);
        bool one = 0;
        rep(c1,0,n){
            cin >> a;
            if(a < k){a = 0;}
            else if(a == k){a = 1;}
            else{a = 2;}
            A[c1] = a;
            if(a == 1)one = 1;
        }
        if(!one){
            cout << "no\n";
            continue;
        }
        bool ok = 0;
        if(n == 1){
            if(A[0] == 1){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
            continue;
        }
        if(n == 2){
            sort(all(A));
            if(A[0] == 1){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
            continue;
        }
        rep(c1,0,n-1){
            vi temp;
            temp.push_back(A[c1]);
            temp.push_back(A[c1+1]);
            sort(all(temp));
            if(temp[0] != 0)ok = 1;
            if(c1 < n-2){
                temp.push_back(A[c1+2]);
                sort(all(temp));
                if(temp[1] != 0)ok = 1;
            }
        }
        if(ok){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }

    }

    return 0;
}