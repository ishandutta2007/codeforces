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
typedef long double ld;

const ll big = 1000000007;

string s;
ll X[27];
ll Y[27];
ll nex[27];
ll ind[26];

char ANS[2][13];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(int x = 0; x < 2; x++){
        for(int y2 = 0; y2 < 13; y2++){
            ll y = y2;
            if(x == 1)y = 12-y2;
            ll i = x*13+y2;
            X[i] = x;
            Y[i] = y;
            nex[i] = (i+1)%26;
        }
    }

    ll start = 0;
    ll diff = 0;
    for(int c1 = 0; c1 < 27; c1++){
        ll a = s[c1]-'A';
        if(ind[a] != 0){
            start = ind[a]-1;
            diff = c1-ind[a];
            break;
        }
        ind[a] = c1+1;
    }
    if(diff == 0){
        cout << "impossible\n";
        return 0;
    }



    X[26] = 1;
    Y[26] = diff/2;
    nex[(diff-1)/2] = 26;
    nex[26] = (diff+1)/2;
    start = (51-diff/2-start)%26;

    for(int c1 = 0; c1 < 27; c1++){
        ANS[X[start]][Y[start]] = s[c1];
        start = nex[start];
    }

    for(int c1 = 0; c1 < 2; c1++){
        for(int c2 = 0; c2 < 13; c2++){
            cout << ANS[c1][c2];
        }cout << "\n";
    }

    return 0;
}