#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

int arr[201];

void solve() {
    int n; cin >> n; int f = 0;
    range(i, n) {
        char a; cin >> a;
        if (a == 'B') {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
        f += arr[i];
    }
    vector<int> ans;
    if (f % 2 != n % 2) {
        range(i, n) {
            if (arr[i]) {
                if (i == n - 1) {
                    cout << -1;
                    return;
                }
                arr[i] = !arr[i];
                arr[i + 1] = !arr[i + 1];
                ans.push_back(i + 1);
            }
        }
    } else {
        range(i, n) {
            if (!arr[i]) {
                if (i == n - 1) {
                    cout << -1;
                    return;
                }
                arr[i] = !arr[i];
                arr[i + 1] = !arr[i + 1];
                ans.push_back(i + 1);
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto v: ans) {
        cout << v << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}