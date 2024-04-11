#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,q;
ll T;

vi A;
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;
    for(int c1 = 0; c1 < n;c1++){cin >> a;A.push_back(a);}
    if(n <= 2){
        cout << 0 << "\n";
    }
    else{
        ll ans = n+1;
        for(int c1 = -1; c1 <= 1; c1++){
            for(int c2 = -1; c2 <= 1; c2++){
                a = A[0]+c1;
                b = A[1]+c2;
                ll temp = abs(c1)+abs(c2);
                for(int c3 = 2; c3 < n; c3++){
                    c = (b-a)*(c3-1) + b;
                    if(abs(c-A[c3]) <= 1){
                        temp += abs(c-A[c3]);
                    }else{temp += big;}
                }
                ans = min(ans, temp);
            }
        }
        if(ans == n+1)ans = -1;
        cout << ans << "\n";
    }
    return 0;
}