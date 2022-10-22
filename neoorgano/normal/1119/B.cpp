#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int arr[MAXN];
int b[MAXN];
int h;

bool check(int k) {
    int hig = 0;
    for (int i = 0; i < k; ++i) {
        b[i] = arr[i];
    }
    sort(b, b + k);
    reverse(b, b + k);
    /*for (int i = 0; i < k; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < k; i += 2) {
        hig += b[i];
    }
    /*if (k % 2) {
        hig += arr[k - 1];
    }*/
    // cout << hig << " | " << h << endl;
    return hig <= h;
}

main() {
    int n;
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
        /*for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;*/
    }
    // cout << check(4) << endl;
    cout << l;
    return 0;
}