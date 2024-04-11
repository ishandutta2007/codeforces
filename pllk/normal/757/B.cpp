#include <iostream>

using namespace std;

int x[101010];
int n;
int p = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        x[u]++;
    }
    for (int i = 2; i <= 100000; i++) {
        int u = 0;
        for (int j = i; j <= 100000; j += i) {
            u += x[j];
        }
        p = max(p,u);
    }
    cout << p << "\n";
}