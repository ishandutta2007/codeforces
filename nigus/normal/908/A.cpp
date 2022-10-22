#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

string bad = "aeiuo13579";

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    string s;
    cin >> s;
    ll ans = 0;
    for(int c1 = 0; c1 < s.length(); c1++){
        for(int c2 = 0; c2 < bad.length(); c2++){
            if(s[c1] == bad[c2]){
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}