#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
pair<int, int> arr[MAXN];

main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].first;
            k += arr[i].first;
            arr[i].second = i + 1;
        }
        k *= 2;
        if (m < n || n == 2) {
            cout << -1 << endl;
            continue;
        }
        sort(arr, arr + n);
        k += (m - n) * (arr[0].first + arr[1].first);
        cout << k << endl;
        while (m > n) {
            cout << arr[0].second << " " << arr[1].second << endl;
            m--;
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i].second << " " << arr[(i + 1) % n].second << endl;
        }
    }
    return 0;
}