#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 10000000000000000;
const int Y = 1000000;
const long long m = 1000000007;
long long arr[Y+2];  
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO";
        return 0;
    }
    vector<pair<long long, string>>ans;
    for (int i = 1; i < n; ++i) {
        if (!k)break;
        ans.push_back({ 0,"R" });
        for (int j = 1; j < m && k; ++j, --k)++ans[ans.size() - 1].first;
        if (!k)break;
        ans.push_back({ 0,"DUL" });
        for (int j = m; j > 1 && k; --j) {
            if (k >= 3) {
                k -= 3;
                ++ans[ans.size() - 1].first;
            }
            else {
                if (k == 2) {
                    ans.push_back({ 1,"DU" });
                    k -= 2;
                }
                else {
                    ans.push_back({ 1,"D" });
                    --k;
                }
            }
        }
        if (!k)break;
        ans.push_back({ 1,"D" });
        --k;
    }
    if (k) {
        ans.push_back({ 0,"R" });
        for (int j = 1; j < m && k; ++j, --k)++ans[ans.size() - 1].first;
    }
    if (k) {
        ans.push_back({ 0,"L" });
        for (int j = 1; j < m && k; ++j, --k)++ans[ans.size() - 1].first;
    }
    if (k) {
        ans.push_back({ 0,"U" });
        for (int j = 1; j < n && k; ++j, --k)++ans[ans.size() - 1].first;
    }
    cout << "YES\n";
    vector<pair<long long, string>>ans1;
    for (auto x : ans) {
        if (x.first)ans1.push_back(x);
    }
    cout << ans1.size() << "\n";
    for (auto x : ans1)cout << x.first << " " << x.second << "\n";
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */