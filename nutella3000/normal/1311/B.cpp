#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = (1 << 19);



signed main() {
    //freopen("inpur.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    for(int q = 0;q < test;q++) {
        int n, m;
        cin >> n >> m;
        int a[n];
        bool b[n];
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            b[i] = false;
        }
        for(int i = 0;i < m;i++) {
            int p;
            cin >> p;
            b[p - 1] = true;
        }
        bool bad = false;
        for(int i = 0;i < n;i++) {
            int id = i;
            for(int j = i;j < n;j++) {
                if (a[id] > a[j]) id = j;
            }

            while(id != i) {
                if (!b[id - 1]) {
                    bad = true;
                    break;
                }
                swap(a[id], a[id - 1]);
                id--;
            }
        }
        if (bad) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

}