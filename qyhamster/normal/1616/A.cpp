#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        set<int> s;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(s.count(a[i])) s.insert(-a[i]);
            else s.insert(a[i]);
        }
        cout << s.size() << endl;
    }
    return 0;
}