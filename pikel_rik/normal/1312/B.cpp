#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool isGood(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = i+1; j < a.size(); j++) {
            if (i - a[i] == j - a[j])
                return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> ans(t);

    for (int T = 0; T < t; T++) {
        int n;
        cin >> n;

        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        while (!isGood(a))
            for (int i = 0; i < a.size(); i++) {
                for (int j = i+1; j < a.size(); j++) {
                    if (i - a[i] == j - a[j])
                        swap(a[i], a[j]);
                }
            }
        ans[T] = a;
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}