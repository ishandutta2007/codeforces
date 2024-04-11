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
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<long long>s(2 * n);
        for (auto& x : s)cin >> x;
        sort(s.begin(), s.end());
        long long M = s[n] - s[n - 1];
        cout << M << "\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */