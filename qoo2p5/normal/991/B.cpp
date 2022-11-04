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

int calc(vector<int> &a) {
    int sum = 0;
    for (int x : a) {
        sum += x;
    }
    return (int) round((double) sum / (int) a.size() + 1e-7);
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (calc(a) == 5) {
            cout << i << "\n";
            return;
        }
        a[i] = 5;
    }

    cout << n << "\n";
}