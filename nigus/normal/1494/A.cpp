#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAXN = 201;
const ll big = 1000000007;

ll F[3] = {0};
ll S[3] = {0};
string s;

int main() {
    ll T;
    cin >> T;
    rep(c4,0,T){
        cin >> s;
        rep(c1,0,3){
            F[c1] = 0;
            S[c1] = 0;
        }
        ll n = sz(s);
        rep(c1,0,n){
            F[s[c1]-'A']++;
        }
        S[s[0]-'A'] = 1;
        if(s[0] == s[n-1]){
            cout << "NO\n";
            continue;
        }
        S[s[n-1]-'A'] = -1;
        ll balance = F[s[0]-'A']-F[s[n-1]-'A'];
        rep(c1,0,3){
            if(S[c1] == 0){
                if(F[c1] + balance == 0){
                    S[c1] = 1;
                }
                else{
                    S[c1] = -1;
                }
            }
        }
        bool yes = 1;
        ll sum = 0;
        rep(c1,0,n){
            sum += S[s[c1]-'A'];
            if(sum < 0)yes = 0;
        }
        if(sum != 0)yes = 0;
        if(yes){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}