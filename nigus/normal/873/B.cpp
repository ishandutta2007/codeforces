#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,T;

ll F[200001] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    string s;
    cin >> s;
    ll cs = 0;
    ll ex = 100000;
    F[ex] = 1;

    ll ans = 0;

    for(ll c1 = 0; c1 < n; c1++){
        a = 2*(s[c1]-'0')-1;
        cs += a;
        if(F[ex+cs] == 0){
            F[ex+cs] = c1+2;
        }
        else{
            ans = max(ans, c1+2-F[ex+cs]);
        }
    }
    cout << ans << "\n";
    return 0;
}