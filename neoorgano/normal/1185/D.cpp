#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
pair<int, int> arr[MAXN];
int n;

bool check(int j) {
    if (n <= 2) {
        return true;
    }
    vector<int> arr2;
    for (int i = 0; i < n; ++i) {
        if (arr[i].second != j) {
            arr2.push_back(arr[i].first);
        }
    }
    sort(arr2.begin(), arr2.end());
    int c = arr2[1] - arr2[0];
    for (int i = 1; i < n - 1; ++i) {
        if (arr2[i] - arr2[i - 1] != c) {
            return false;
        }
    }
    return true;
}

main() {
    cin >> n;
    if (n <= 2) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    if (check(arr[0].second)) {
        cout << arr[0].second + 1;
        return 0;
    }
    if (check(arr[1].second)) {
        cout << arr[1].second + 1;
        return 0;
    }
    int c = arr[1].first - arr[0].first;
    for (int i = 2; i < n; ++i) {
        if (arr[i].first - arr[i - 1].first != c) {
            if (check(arr[i].second)) {
                cout << arr[i].second + 1;
                return 0;
            } else {
                cout << -1;
                return 0;
            }
        }
    }
    return 0;
}