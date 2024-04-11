#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(_v) _v.begin(), _v.end()
typedef long double ld;

const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    int num = 0;
    vector<int> cnt(x);

    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        cnt[v % x]++;
        while(cnt[num % x]) {
            cnt[num % x]--;
            num++;
        }

        cout << num << endl;
    }
}