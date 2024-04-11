#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    string s;
    cin >> s;
    bool ans = 0;
    for(int c1 = 0; c1 < 5; c1++){
        string s2;
        cin >> s2;
        if(s2[0] == s[0] || s2[1] == s[1])ans = 1;
    }
    if(ans){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}