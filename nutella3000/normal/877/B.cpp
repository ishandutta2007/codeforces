#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    string s;
    cin >> s;
    int n = s.size();

    int res = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for(int l = 0;l < n;l++) {
        cnt1 = cnt2 = cnt3 = 0;
        for(int i = 0;i < n;i++) {
            if (s[i] != 'a') continue;
            if (i < l) cnt1++;
            else cnt2++;
        }

        for(int r = l - 1;r < n;r++) {
            res = max(res, cnt1 + cnt2 + cnt3);
            if (r + 1 < n) {
                if (s[r + 1] == 'a') cnt3--;
                if (s[r + 1] == 'b') cnt2++;
            }
        }
    }

    cout << res;
}