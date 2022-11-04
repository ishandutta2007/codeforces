#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int arr[MAXN + 1];

multiset <int> mst;
map <int, int> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, d, i, x;
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    d++;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        mst.insert(arr[i]);
    }
    int ans = 0;
    while(!mst.empty()) {
        ans++;
        int last = *mst.begin();
        mst.erase(mst.begin());
        while(1) {
            mp[last] = ans;
            auto it = mst.lower_bound(last + d);
            if(it == mst.end()) {
                break;
            }
            last = *it;
            mst.erase(it);
        }
    }
    cout << ans << "\n";
    for(i = 1; i <= n; i++) {
        cout << mp[arr[i]] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}