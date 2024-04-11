#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count  = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < 0) ++count;
    }
    if (count <= 1 || count >= n - 1) cout << "Yes";
    else cout << "No";
    return 0;
}