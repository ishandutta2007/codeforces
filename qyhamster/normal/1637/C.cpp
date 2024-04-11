#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e5 + 5;
long long a[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n == 3) {
            if(a[1]%2 == 0) {
                cout << a[1]/2 << endl;
            }
            else cout << -1 << endl;
            continue;
        }
        long long nonzeros = 0, multi = 0, sum = 0, ans = 0;
        for(int i = 1; i < n-1; i++) {
            if(a[i] > 0) nonzeros++;
            if(a[i] > 1) multi++;
            sum += a[i];
            ans += (a[i]+1)/2;
        }
        if(nonzeros == 0) {
            cout << 0 << endl;
            continue;
        }
        if(nonzeros == 1) {
            if(sum == 1 || sum == 3) cout << -1 << endl;
            else if(sum%2 == 0) cout << sum/2 << endl;
            else {
                cout << (sum+3)/2 << endl;
            }
            continue;
        }
        if(multi) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}