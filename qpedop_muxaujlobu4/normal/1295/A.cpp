#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
using namespace std;
const long long INF = 10000000000;
const int Y = 2000;

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
        string ans = "";
        while (n >= 2 && ans.size() < 998244353) {
            n -= 2;
            ans.push_back('1');
        }
        int len = ans.length();
        for (int i = 0; i < len && n>0; ++i) {
            if (n >= 4) {
                n -= 4;
                ans[i] = '9';
            }
            else {
                --n;
                ans[i] = '7';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/* Wed Jan 29 2020 12:39:03 GMT+0300 (MSK) */

/* Wed Jan 29 2020 13:51:43 GMT+0300 (MSK) */