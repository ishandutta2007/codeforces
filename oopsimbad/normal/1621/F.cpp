#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

ll a, b, c;

ll get(int sum0, int sum1, vector<int> _0, bool turn) {
    int ind0 = 0;
    ll best = 0;
    ll cur = 0;

    int tot = 0;
    while(true) {
        if(turn) {
            if(sum0 == 0) {
                if(ind0 == _0.size() || tot < _0[ind0]-1) return best;
                if(_0[ind0] != 0) {
                    tot -= _0[ind0]-1;
                    sum1++;
                }
                cur -= c;
                ind0++;
            } else if(sum1 == 0) {
                best = max(best, cur + a);
                if(ind0 == _0.size() || tot < _0[ind0]-1) return best;
                if(_0[ind0] != 0) {
                    tot -= _0[ind0]-1;
                    sum1++;
                }
                cur -= c;
                ind0++;
            } else {
                cur += a;
                sum0--;
                tot++;
            }
        } else {
            if(sum1 == 0) return best;
            sum1--;
            cur += b;
        }
        turn ^= 1;
        best = max(best, cur);
    } 
}

int main() {
    int asdf; cin >> asdf;
    while(asdf--) {
        int n; cin >> n >> a >> b >> c;
        string s; cin >> s;
        vector<int> _0, _1;
        
        int cnt = 0;
        char c = s[0];

        bool first = s[0] == '0', last = s[n-1] == '0';
        F0R(i, n) {
            if(c == s[i]) cnt++;
            else {
                if(c == '0') _0.pb(cnt);
                else _1.pb(cnt);
                c = s[i];
                cnt = 1;
            }
        }
        if(c == '0') _0.pb(cnt);
        else _1.pb(cnt);

        int sum0 = 0, sum1 = 0;
        for(int i : _0) sum0 += i-1;
        for(int i : _1) sum1 += i-1;

        if(first) _0.erase(_0.begin());
        if(last && !_0.size() == 0) _0.erase(_0.end()-1);

        sort(_0.begin(), _0.end());

        if(first) _0.pb(0);
        if(last) _0.pb(0);

        cout << max(get(sum0, sum1, _0, false), get(sum0, sum1, _0, true)) << endl;

    }
}