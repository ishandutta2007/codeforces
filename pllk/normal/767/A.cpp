#include <iostream>

using namespace std;

int n;
int x[101010];
int p;

int main() {
    cin >> n;
    p = n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        x[u] = 1;
        while (x[p]) {
            cout << p << " ";
            p--;
        }
        cout << "\n";
    }
}