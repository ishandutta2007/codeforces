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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        long long n, g, b;
        cin >> n >> g >> b;
        if (g >= b||g>=n||(g>=(n+1)/2)) {
            cout << n << "\n";
            continue;
        }
        long long p = 1, e = n + 1;
        while (p + 1 != e) {
            long long tmp = (p + e) / 2;
            if (tmp * g < (n + 1) / 2)p = tmp;
            else e = tmp;
        }
        long long ans = (g + b) * p;
        ans += (n + 1) / 2 - p * g;
        if (n > ans)ans = n;
        cout << ans << "\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */