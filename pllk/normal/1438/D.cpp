#include <iostream>
#include <vector>

using namespace std;

int n;
int a[101010];

vector<vector<int>> r;

void op(int i, int j, int k) {
    int x = a[i]^a[j]^a[k];
    a[i] = a[j] = a[k] = x;
    r.push_back({i,j,k});
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i+2 <= n; i += 2) {
        op(i,i+1,i+2);
    }
    if (n%2 == 0) {
        for (int i = 3; i+1 <= n; i += 2) {
            op(1,i,i+1);
        }
    } else {
        for (int i = 1; i+1 <= n-1; i += 2) {
            op(n,i,i+1);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[1] != a[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << r.size() << "\n";
    for (auto x : r) {
        cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    }
}