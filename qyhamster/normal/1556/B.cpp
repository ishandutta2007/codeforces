#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
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
        int odd = 0;
        for(int i = 0; i < n; i++) {
            if(a[i]&1) odd++;
            else odd--;
        }
        if(odd > 1 || odd < -1) {
            cout << -1 << endl;
            continue;
        }
        if(odd == -1) {
            for(int i = 0; i < n; i++) a[i]++;
            odd = 1;
        }
        if(odd == 1) {
            for(int i = 0; i < n; i++) {
                if(a[i]&1) {
                    swap(a[i], a[0]);
                    ans += i;
                    break;
                }
            }
        }
        int cnt = 0, par = -1;
        if(a[0]&1) par = 1;
        else par = 0;
        for(int i = 1; i < n; i++) {
            if(a[i]&1) {
                if(par == 1) cnt++;
                else {
                    if(cnt > 0) {
                        ans += cnt;
                        cnt--;
                    }
                    else {
                        par = 1;
                    }
                }
            }
            else {
                if(par == 0) cnt++;
                else {
                    if(cnt > 0) {
                        ans += cnt;
                        cnt--;
                    }
                    else par = 0;
                }
            }
        }
        long long T = ans;
        ans = 0;
        for(int i = 1; i < n; i++) {
            if((a[0] + a[i])&1) {
                ans += i;
                swap(a[0], a[i]);
                break;
            }
        }
        cnt = 0, par = -1;
        if(a[0]&1) par = 1;
        else par = 0;
        for(int i = 1; i < n; i++) {
            if(a[i]&1) {
                if(par == 1) cnt++;
                else {
                    if(cnt > 0) {
                        ans += cnt;
                        cnt--;
                    }
                    else {
                        par = 1;
                    }
                }
            }
            else {
                if(par == 0) cnt++;
                else {
                    if(cnt > 0) {
                        ans += cnt;
                        cnt--;
                    }
                    else par = 0;
                }
            }
        }
        if(cnt) ans = 1e18;
        cout << min(T, ans) << endl;
    }
    return 0;
}