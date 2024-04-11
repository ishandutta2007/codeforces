#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> a, vector<int> b) {
    int c = 0;
    for (int i = 31; i >= 0; i--) {
        c += b[i];
        c -= a[i];
        if (c < 0) return false;
    }
    return true;
}

vector<int> move(vector<int> a, int k, int d) {
    int c = 0;
    for (int i = 0; i < 32; i++) {
        if (a[i] == 1) c++;
        if (c == k) {
            if (a[i+1]) return a;
            a[i+1] = 1;
            for (int j = i; j >= 0; j--) {
                if (a[j]) {a[j] = 0; d--;}
                if (d == 0) break;
            }
            return a;
        }
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        vector<int> a(32), b(32);
        for (int i = 0; i < 32; i++) {
            if (u&(1<<i)) a[i] = 1;
            if (v&(1<<i)) b[i] = 1;
        }
        int c1 = __builtin_popcount(u);
        int c2 = __builtin_popcount(v);
        if (c2 > c1) {
            cout << "NO\n";
            continue;
        }
        if (c2 < c1) {
            int d = c1-c2+1;
            int f = 0;
            for (int i = d; i <= c1; i++) {
                auto x = move(a,i,d);
                if (x != a && check(x,b)) {
                    cout << "YES\n";
                    f = 1;
                    break;
                }
            }
            if (!f) cout << "NO\n";
        } else {
            if (check(a,b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}