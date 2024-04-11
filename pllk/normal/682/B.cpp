#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> x;

int main() {
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(),x.end());
    int u = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] >= u) u++;
    }
    cout << u << "\n";
}