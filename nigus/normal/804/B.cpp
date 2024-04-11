#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    string s;
    cin >> s;
    n = s.length();

    ll ans = 0;
    ll nb = 0;
    for(ll c1 = n-1; c1 >= 0; c1--){

        if(s[c1] == 'a'){
            ans += nb;
            nb *= 2;
        }
        else{
            nb++;
        }
        nb %= big;
        ans %= big;

    }

    cout << ans << "\n";

    return 0;
}