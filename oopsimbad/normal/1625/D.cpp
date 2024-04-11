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

const int MAXN = 300005;
int trie[MAXN * 30][2];
pii best[MAXN * 30];
pii dp[MAXN];

int sz = 1;

int main() {
    int n, k; cin >> n >> k;
    vector<pii> v(n);
    F0R(i, n) {
        cin >> v[i].f;
        v[i].s = i;
    }
    if(k == 0) {
        cout << n << endl;
        F0R(i, n) cout << i+1 << " ";
        return 0;
    }
    sort(v.begin(), v.end());
    
    int ind = -1;
    pii ans = {0, -1};
    F0R(i, n) {
        pii bes = {0, -1};
        int cur = 0;
        int b = 1 << 29;
        while(b > 0) {
            bool _1 = v[i].f & b;
            if(!(k & b) && trie[cur][_1 ^ 1]) bes = max(bes, best[trie[cur][_1 ^ 1]]);
            if(k&b) {
                cur = trie[cur][_1^1];
                if(cur == 0) break;
            } else {
                cur = trie[cur][_1];
                if(cur == 0) break;
            }
            b >>= 1;
        }
        if(b == 0 && cur != 0) bes = max(bes, best[cur]);

        dp[i] = bes;
        b = 1 << 29;
        cur = 0;
        while(b > 0) {
            bool _1 = v[i].f & b;
            if(!trie[cur][_1]) {
                best[sz] = {bes.f + 1, i};
                trie[cur][_1] = sz++;
            }
            best[cur] = max(best[cur], {bes.f + 1, i});
            cur = trie[cur][_1];
            b >>= 1;
        }

        if(bes > ans) {
            ans = bes;
            ind = i;
        }
    }

    if(ind == -1) cout << -1 << endl;
    else {
        cout << ans.f + 1 << endl;
        while(ind != -1) {
            cout << v[ind].s+1 << " ";
            ind = dp[ind].s;
        }
    }
}