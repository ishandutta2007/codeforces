#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x[1111], y[1111];

vector<int> v;

void end() {
    cout << v.size() << "\n";
    for (auto x : v) cout << x << " ";
    cout << "\n";
    exit(0);
}

void lol() {
    v.clear();
    for (int i = 1; i <= n; i++) {
        if (x[i]%2 == y[i]%2) v.push_back(i);
    }
    if (v.size() != 0 && v.size() != n) end();
    v.clear();
    for (int i = 1; i <= n; i++) {
        if (x[i]%2 == 0) v.push_back(i);
    }
    if (v.size() != 0 && v.size() != n) end();
    for (int i = 1; i <= n; i++) {
        if (x[i]%2 == 1) {x[i]++; y[i]++;}
        x[i] /= 2; y[i] /= 2;
    }
    lol();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        x[i] += 2000000;
        y[i] += 2000000;
    }
    lol();
}