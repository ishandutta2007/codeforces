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
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;
 
const int inf = 1e16;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];

        vector<int> cnt(2);
        for(int i = 0;i < n;i++) 
            cnt[a[i]]++;

        int num = (cnt[0] >= cnt[1] ? 0 : 1);
        int c = n - min(cnt[0], cnt[1]);
        if (cnt[0] < cnt[1] && cnt[1] % 2 == 1) c--;

        cout << c << endl;
        for(int i = 0;i < c;i++)
            cout << num << " ";

        cout << endl;
    }
}