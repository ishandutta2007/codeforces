#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

bool ok(int x) {
    if (x < 2) return 0;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) return 0;
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (ok(i)) {
            int x = i;
            while (x <= n) {
                v.push_back(x);
                x *= i;
            }
        }
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}