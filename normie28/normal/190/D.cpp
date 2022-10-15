#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>
map<int, int> cnt;
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(555555, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p1 = 0, p2 = 0;
    cnt[a[0]]++;
    int ans = 0;
    while(p2 < n) {
        if(cnt[a[p2]] < k) {
            p2++;
            cnt[a[p2]]++;
        }
        else
        {
            ans += n - p2;
            cnt[a[p1]]--;
            p1++;
        }
 
    }
    cout << ans << "\n";
 
}