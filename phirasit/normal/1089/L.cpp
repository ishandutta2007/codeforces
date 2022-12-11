#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    
    set<int> s;
    map<int, int> cnt;
    vector<int> a(n), b(n);
    vector<pair<int, int>> data;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        cnt[a[i]]++;
        data.push_back({b[i], a[i]});
    }

    sort(data.begin(), data.end());

    long long ans = 0ll;
    for (pair<int, int> p : data) {
        if (cnt[p.second] == 1) continue;
        if (s.size() >= k) continue;

        ans += p.first;
        cnt[p.second]--;
        --k;
    }

    cout << ans << endl;

    return 0;
}