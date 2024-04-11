#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                if(a[j] == 0) sum += 2;
                else sum += 1;
                ans += sum;
            }
        }
        cout << ans << endl;
    }
    return 0;
}