#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> e[maxn];
int a[maxn], ip[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i < maxn; i++) {
        if(ip[i]) continue;
        for(int j = i+i; j < maxn; j += i)
            ip[j] = 1;
    }
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) e[i].clear();
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            e[i%m].push_back(a[i]);
        }
        long long ans = 0;
        for(int i = 0; i < m; i++) {
            long long cnt = 0;
            for(auto k: e[i]) {
                if(ip[k] == 0 && k > 1) ans--;
                if(k == 1) {
                    cnt++;
                    ans -= cnt;
                }
                else {
                    cnt = 0;
                }
            }
            int lst1 = -1, lst2 = -1;
            for(int j = 0; j < e[i].size(); j++) {
                if(e[i][j] > 1) {
                    if(ip[e[i][j]] == 1) lst1 = lst2 = j;
                    else {
                        lst1 = lst2;
                        lst2 = j;
                    }
                }
                ans += j - lst1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}