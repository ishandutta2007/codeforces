#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;




signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int res = 0;
        vector<int> cnt;
        int c = 0;
        char last = -1;
        for(int i = 0;i <= n;i++) {
            if (i == n || s[i] != last) {
                if (i != 0 && s[i - 1] == '1') cnt.emplace_back(c);
                c = 1;
                if (i != n)
                    last = s[i];
            }else c++;
        }

        sort(all(cnt));
        for(int i = (int)cnt.size() - 1;i >= 0;i-= 2) res += cnt[i];

            cout << res << endl;
    }
}