#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

//#define MAX_N 1000010

vector<int> j, z;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <=n; i++) {
        char a;
        cin >> a;
        if (a == '1') {
            j.push_back(i);
        } else {
            z.push_back(i);
        }
    }

    if (j.empty() || z.empty()) {
        cout << "tokitsukaze";
        return 0;
    }

    if (j.back() - j.front() + 1 <= k) {
        cout << "tokitsukaze";
        return 0;
    }

    if (z.back() - z.front() + 1 <= k) {
        cout << "tokitsukaze";
        return 0;
    }

    for (int pocz, kon, i = 1; i + k - 1 <= n; i++) {
        //zmiana na 1
        for (int qqq = 0; qqq < 2; qqq++) {
            pocz = z.front();
            kon = z.back();

            if (i <= pocz && pocz < i + k) {
                pocz = *lower_bound(z.begin(), z.end(), i + k);
            }

            if (i <= kon && kon < i + k) {
                auto it = lower_bound(z.begin(), z.end(), i);
                it--;
                kon = *it;
            }

            if (kon - pocz + 1 > k) {
                cout << "once again";
                return 0;
            }

            swap(j, z);
        }
    }

    cout << "quailty";

    return 0;
}
/*

*/