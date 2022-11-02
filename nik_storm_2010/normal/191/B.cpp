#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int N = 1e5 + 10;

int a[N];
set <int> used;
vector <int> c;

int main() {
    int n, k;
    cin >> n >> k;
    long long b;
    cin >> b;
    c.resize(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i - 1] = a[i];
    }
    c.pop_back();
    sort(c.rbegin(), c.rend());
    long long sum = 0;
    for (int i = 0; i < k - 1; i++) {
        if (used.find(c[i]) == used.end()) {
            used.insert(c[i]);
        }
        sum += c[i];
    }
    for (int i = 1; i < n; i++) {
        long long cur_sum = sum;
        if (used.find(a[i]) != used.end()) {
            cur_sum += c[k - 1];
        } else {
            cur_sum += a[i];
        }
        if (cur_sum > b) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}