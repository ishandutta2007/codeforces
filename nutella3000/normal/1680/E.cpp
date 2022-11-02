#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e15 + 7;
const int N = 500;

void run() {
    int n;
    vector<string> s(2);
    cin >> n >> s[0] >> s[1];

    int mx = n-1;
    while (mx >= 0 && s[0][mx] == '.' && s[1][mx] == '.')
        --mx;

    int res = 0, msk = 0;
    for (int i = 0; i <= mx; ++i) {
        if (msk != 0) ++res;

        int v1 = s[0][i] == '*';
        int v2 = s[1][i] == '*';
        int tom = v1 | (v2 << 1);

        if (!tom) continue;
        
        if (tom == 3) msk = 3;
        else if ((msk & tom) == tom) msk = tom;
        else msk |= tom;


        if (msk == 3) ++res;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}