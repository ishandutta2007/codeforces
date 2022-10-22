#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;

ll n,m,T,k,q;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> m >> b;
    ll ans = 0;
    for(ll c1 = 0; c1 <= b*m; c1++){
        ll dy = (b*m - c1)/m + 1;
        ll dx = c1+1;
        ll temp = dy*((dx*(dx-1))/2) + dx*((dy*(dy-1))/2);

        //1cout << c1 << " " << dy << "\n";

        ans = max(ans,temp);
    }
    cout << ans << "\n";

    return 0;
}