#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[1111];
int d[1111];

int main() {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        d[a]++; d[b]++;
    }
    while (true) {
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 1 && a == 0) a = i;
            else if (d[i] == 1 && b == 0) b = i;
        }
        if (b == 0) {
            for (int i = 1; i <= n; i++) {
                if (d[i] > -1) {
                    cout << "! " << i << endl;
                    return 0;
                }
            }
        }
        cout << "? " << a << " " << b << endl;
        int x;
        cin >> x;
        if (x == a) {
            cout << "! " << a << endl;
            return 0;
        }
        if (x == b) {
            cout << "! " << b << endl;
            return 0;
        }
        d[a] = -1; d[b] = -1;
        for (auto u : v[a]) d[u]--;
        for (auto u : v[b]) d[u]--;
    }
}