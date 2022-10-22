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
ll n,k,m,d;

vl A;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s += '*';
    c = 0;
    for(int c1 = 0; c1 < n+1; c1++){
        if(s[c1] == '.'){
            c++;
        }
        else{
            if(c != 0)A.push_back(c);
            c = 0;
        }
    }

    sort(all(A));

    ll ans = 0;

    for(int c1 = 0; c1 < sz(A); c1++){
        ll x = A[c1]/2;
        ll y = A[c1]/2+A[c1]%2;
        if(a > b){
            c = x;
            x = y;
            y = c;
        }
        x = min(x,a);
        a-=x;
        y = min(y,b);
        b-=y;
        ans += x+y;
    }
    cout << ans << "\n";
    return 0;
}