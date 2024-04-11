#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int arr[MAXN];
int arr1[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
    }
    arr1[0] = 1;
    for (int i = 1; i < n; ++i) {
        arr1[i] = arr1[i - 1] + arr[i];
    }
    unordered_set<int> st;
    for (int i = 0; i < n; ++i) {
        st.insert(arr1[i]);
    }
    if (st.size() < n) {
        cout << -1;
        return 0;
    }
    int minel = 1;
    int maxel = 1;
    for (int i = 0; i < n; ++i) {
        if (arr1[i] < minel) {
            minel = arr1[i];
        }
        if (arr1[i] > maxel) {
            maxel = arr1[i];
        }
    }
    if (maxel - minel + 1 != n) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << arr1[i] - minel + 1 << " ";
    }
    return 0;
}