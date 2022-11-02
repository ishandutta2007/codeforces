#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, p;
        string s;
        cin >> a >> b >> p >> s;
        int n = s.size();

        int sum = 0, res = n - 1;

        for(int i = n - 3;i >= 0;i--) {
            if (s[i] != s[i + 1]) {
                if (s[i + 1] == 'A') sum += a;
                else sum += b;
                if (sum <= p) res = i + 1;
            }
        }
        if (s[0] == 'A') sum += a;
        else sum += b;
        if (sum <= p) res = 0;

        cout << res + 1 << endl;
    }  
}