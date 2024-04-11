#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ind = 0;
    int next = 0;
    int cnt = 0;
    while (ind != n-1) {
        cnt++;
        for (int i = ind; i < n; ++i) {
            if (v[i] - v[ind] > k) {
                next = i-1;
                break;
            }
            if (i == n-1) {
                next = n-1;
            }
        }
        if (ind == next) return !(cout << -1);
        ind = next;
    }
    cout << cnt;
    return 0;
}