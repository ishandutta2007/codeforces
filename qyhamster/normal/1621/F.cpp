#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 1000;
int a[maxn][maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        long long a, b, c;
        long long ans = 0;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int zeros = 0, ones = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                if(s[i] == '0') zeros++;
                else ones++;
            }
        }
        vector<int> vec;
        int lst = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(lst == -1) lst = i;
                else {
                    if(lst == i-1) {
                        lst = i;
                        continue;
                    }
                    vec.push_back(i-lst-2);
                    lst = i;
                }
            }
        }
        sort(vec.begin(), vec.end());
        if(zeros >= ones) {
            ans += ones * b + ones * a;
            if(b > c) {
                int x = ones;
                for(auto k: vec) {
                    if(x >= k) {
                        ans += (b-c);
                        x -= k;
                    }
                    else break;
                }
            }
            if(zeros > ones) ans += a;
        }
        else {
            ans += zeros * a + (zeros+1) * b;
            if(b > c) {
                int L = -zeros-2, Z = -zeros;
                for(int i = 0; i < n; i++) {
                    if(s[i] == '0') Z++;
                    else L++;
                }
                ans += min(L, Z) * (b-c);
            }
        }
        cout << ans << endl;
    }
    return 0;
}