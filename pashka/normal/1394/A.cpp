#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a(n);
    vector<int> good;
    vector<int> bad;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > m) {
            bad.push_back(x);
        } else {
            good.push_back(x);
        }
    }
    sort(good.rbegin(), good.rend());
    sort(bad.rbegin(), bad.rend());
    long sg = 0;
    long sb = 0;
    for (int x : good) sg += x;
    long res = sg;
    int j = good.size();
    for (int i = 1; i <= bad.size(); i++) {
        sb += bad[i - 1];
        int mx = n - 1 - (d + 1) * (i - 1);
        if (mx < 0) break;
        while (j > mx) {
            sg -= good[j - 1];
            j--;
        }
//        cout << sb << " " << sg << "\n";
        res = max(res, sg + sb);
    }
    cout << res << "\n";
    return 0;
}