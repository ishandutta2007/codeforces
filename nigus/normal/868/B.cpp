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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> a >> b >> c;
    a*=10;
    a%=120;
    b *= 2;
    c *= 2;
    a++;
    b++;

    cin >> n >> m;
    n *= 10;
    n %= 120;
    m *= 10;
    m %= 120;

    ll mil = 120;
    ll mir = 120;
    string ans = "NO";
    mil = min(mil, (n-a+120)%120);
    mil = min(mil, (n-b+120)%120);
    mil = min(mil, (n-c+120)%120);

    mir = min(mir, (a-n+120)%120);
    mir = min(mir, (b-n+120)%120);
    mir = min(mir, (c-n+120)%120);

   // cout << mil << " " << mir << "\n";

    if((n-m+120)%120 < mil){
        ans = "YES";
    }
    if((m-n+120)%120 < mir){
        ans = "YES";
    }

    cout << ans << "\n";

    return 0;
}