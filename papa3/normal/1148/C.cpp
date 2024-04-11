#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int tab[1000010];
int gdzie[1000010];
vector<pair<int, int> > v;

void zmien(int a, int b) {
    if (a == b) return;
    v.push_back({a, b});
    gdzie[tab[a]] = b;
    gdzie[tab[b]] = a;
    swap(tab[a], tab[b]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tab[i];
        gdzie[tab[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (gdzie[i] == i) continue;

        int x = gdzie[i];
        if (i <= n/2) {
            if (x <= n/2) {
                zmien(x, n);
                zmien(i, n);
                zmien(x, n);
            } else {
                zmien(x, 1);
                zmien(1, n);
                zmien(i, n);
                if (x != n && i != 1) {
                    zmien(1, x);
                }
            }
        } else {
            if (x > n/2) {
                zmien(x, 1);
                zmien(i, 1);
                zmien(x, 1);
            } else {
                zmien(x, n);
                zmien(n, 1);
                zmien(i, 1);
                zmien(1, n);
            }
        }

        //for (int i = 1; i <= n; i++) {cout << tab[i] << " ";}cout << endl;
    }

    cout << v.size() << "\n";
    for (pair<int, int> i : v) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}
/*

*/