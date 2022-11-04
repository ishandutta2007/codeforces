#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

void NO() {
    cout << "-1\n";
    exit(0);
}

void run() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (a < c || b < c) {
        NO();
    }
    int tot = a + b - c;
    if (tot >= n) {
        NO();
    }
    cout << n - tot << "\n";
}