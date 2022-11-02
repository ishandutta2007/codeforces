#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
typedef pair<double, int> p;

int main() { 
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    vector<p> records[1001];
    for (int i = 0; i < n; ++i) {
        double y = r;
        for (int x = max(1, arr[i] - 2 * r); x <= min(1000, arr[i] + 2 * r); ++x) 
            if (records[x].size() > 0) {
                y = max(y, records[x].back().first + sqrt((double)(4 * r * r - (arr[i] - x) * (arr[i] - x))));
            }
        records[arr[i]].push_back(make_pair(y, i));
    }
    vector<double> ans(n, 0);
    for (int i = 1; i < 1001; ++i)
        for (auto j : records[i])
            ans[j.second] = j.first;
    cout << fixed << setprecision(10);
    for (auto i : ans) cout << i << ' ';
    //system("pause");
    return 0; 
}