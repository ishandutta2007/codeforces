#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    vector<bool> used(n);
    deque<int> que;
    int ans = 0, ptr = 0;
    for (int i = 1; i <= 1e6; ++i) {
        while (que.size() > 0 && que.front() < i) que.pop_front();
        while (ptr < n && arr[ptr] < i + m) que.push_back(arr[ptr++]);
        while (que.size() >= k) {
            ++ans;
            que.pop_back();
        }
    }
    cout << ans;
    //system("pause");
    return 0;
}