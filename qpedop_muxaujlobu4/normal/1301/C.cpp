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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long long n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << 0 << "\n";
            continue;
        }
        long long res = (n + 1) * n / 2;
        long long ct1 = m + 1, ct0 = n - m;
        long long tmp1 = ct0 / ct1, tmp2 = ct0 % ct1;
        long long tmp3 = ct1 - tmp2;
        res -= tmp3 * (tmp1 * (tmp1 + 1) / 2);
        ++tmp1;
        res -= tmp2 * (tmp1 * (tmp1 + 1) / 2);
        cout << res << "\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */