#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int flag = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0)
            flag = 1;
    }

    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans0;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            ans1.push_back(a[i]);
            v[i] = 1;
            break;
        }
    }

    if (flag == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                ans2.push_back(a[i]);
                v[i] = 1;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (a[i] < 0 and v[i] == 0) {
                ans2.push_back(a[i]);
                v[i] = 1;
            }
            if (ans2.size() == 2)
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == 0)
            ans0.push_back(a[i]);
    }

    cout << ans1.size();
    for (int i = 0; i < ans1.size(); i++) {
        cout << " " << ans1[i];
    }

    cout << "\n" << ans2.size();
    for (int i = 0; i < ans2.size(); i++) {
        cout << " " << ans2[i];
    }

    cout << "\n" << ans0.size();
    for (int i = 0; i < ans0.size(); i++) {
        cout << " " << ans0[i];
    }


    return 0;
}