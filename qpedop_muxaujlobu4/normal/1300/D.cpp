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
const int Y = 200000;
const long long m = 1000000007;
int ct[64];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<long long,long long>>d(n);
    vector<pair<long long, long long>>d1(n);
    if (n % 2 == 1) {
        cout << "NO";
        return 0;
    }
    for (auto& x : d)cin >> x.first >> x.second;
    d1[0] = { d[0].first - d[n - 1].first,d[0].second - d[n - 1].second };
    for (int i = 1; i < n; ++i) {
        d1[i] = { d[i].first - d[i - 1].first,d[i].second - d[i - 1].second };
    }
    for (int i = 0, j = n / 2; j < n; ++i, ++j) {
        if (abs(d1[i].first) != abs(d1[j].first) || abs(d1[i].second) != abs(d1[j].second)) {
            cout<<"NO";
            return 0;
        }
        if (d1[i].first * d1[j].second - d1[i].second * d1[j].first != 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */