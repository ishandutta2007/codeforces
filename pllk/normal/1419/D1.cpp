#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2 0 3 1 4
// 3 0 4 1 5 2 6
//
// 3 0 4 1 5 2

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << (n-1)/2 << "\n";
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) {
            cout << v[n/2+i/2] << " ";
        } else {
            cout << v[i/2] << " ";
        }
    }
    cout << "\n";
}