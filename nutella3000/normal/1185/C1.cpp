#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int inf = 1e9;
int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, M;
    cin >> n >> M;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    int b[101];
    for(int i = 0;i < 101;i++) b[i] = 0;
    int sum = 0;
    for(int i = 0;i < n;i++) {
        int now = 0;
        int now_ = 0;
        for(int j = 100;j >= 1;j--) {
            if (sum - b[j] * j + a[i] - now_ > M) {
                now += b[j];
                now_ += b[j] * j;
            }
            else{
                //sum + a[i] - M >= b[j] * k;
                //k  < sum + a[i] - M) / b[j];
                int k = (sum + a[i] - now_ - M + j - 1) / j;
                if (k < 0) k = 0;
                now += k;
                break;
            }
        }
        cout << now << '\n';
        b[a[i]]++;
        sum += a[i];
    }
}