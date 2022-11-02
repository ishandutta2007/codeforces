#include <bits/stdc++.h>
using namespace std;

#define long long long
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int j = 0;j < n;j++) cin >> a[j];
        int min_ans = 1e9;
        int id = 0;
        for(int j = 0;j < n - k;j++) {
            if (min_ans > a[j + k] - a[j]) {
                id = (a[j + k] + a[j]) / 2;
                min_ans = a[j + k] - a[j];
            }
        }
        cout << id << '\n';
    }
}