#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], c[maxn];
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n,k;
        cin >> n >> k;
        for(int i = 0; i <= n+2; i++) c[i] = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < n) c[a[i]]++;
            else c[n]++;
        }
        sort(a, a+n);
        int cnt = 0, lst = n;
        for(int i = 0; i < n; i++) {
            if(c[i] == 0) cnt++;
            if(cnt > k) {
                lst = i;
                break;
            }
        }
        vector<int> vec;
        int num = 1;
        a[n] = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] < lst) continue;
            if(a[i] != a[i+1]) {
                vec.push_back(num);
                num = 1;
            }
            else num++;
        }
        sort(vec.begin(), vec.end());
        int ans = vec.size(), d = k;
        for(auto x:vec) {
            if(x <= d) {
                d -= x;
                ans--;
            }
        }
        cout << ans << endl;
    }
}