#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    if (n == 1) {
        cout << 2 << " " << 1 << '\n' << 1 << " " << 2;
        return 0;
    }
    int one = 4 * n - 3;
    int two = 4 * n - 2;
    cout << 4 * n - 2 << " " << n * (4 * n - 2) / 2 << '\n';
    for(int i = 1;i < n;i++) {
        for(int j = n;j < 2 * n - 1;j++) {
            cout << i << " " << j << '\n';
            cout << i + 2 * n - 2 << " " << j + 2 * n - 2 << '\n';
        }
    }
    for(int i = n;i < 2 * n - 1;i+= 2) {
        cout << i << " " << i + 1 << '\n';
        cout << i + 2 * n - 2 << " " << i + 2 * n - 1 << '\n';
    }
    for(int i = 1;i < n;i++) {
        cout << i << " " << one << '\n';
        cout << i + 2 * n - 2 << " " << two << '\n';
    }
    cout << one << " " << two;
}