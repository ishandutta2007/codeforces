#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int q;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int u = -1;
        for (int b = n; b >= 1; b /= 2) {
            while (u+b < n && v[u+b] <= x) u += b;
        }
        cout << u+1 << "\n";
    }
}