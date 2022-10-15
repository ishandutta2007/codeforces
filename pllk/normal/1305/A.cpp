#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void lol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    sort(b.begin(),b.end());
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}