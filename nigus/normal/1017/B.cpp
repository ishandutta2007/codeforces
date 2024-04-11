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
typedef pair<double,double> pdd;


const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

ll F[2][2] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    string s1,s2;
    cin >> n;
    cin >> s1 >> s2;

    for(int c1 = 0; c1 < n; c1++){
        a = s1[c1]-'0';
        b = s2[c1]-'0';
        F[a][b]++;
    }

    ll ans = F[0][0]*F[1][0];
    ans += F[1][0]*F[0][1];
    ans += F[0][0]*F[1][1];

    cout << ans << "\n";

    return 0;
}