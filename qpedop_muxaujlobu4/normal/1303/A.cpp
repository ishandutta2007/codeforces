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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        int j1 = -1, j2 = -1;
        cin >> s;
        int len = s.length();
        for (int j = 0; j < len; ++j) {
            if (s[j] == '1') {
                if (j1 == -1) {
                    j1 = j;
                }
                j2 = j;
            }
        }
        if (j1 == -1) {
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        for (int j = j1; j <= j2; ++j)if (s[j] == '0')++ans;
        cout << ans << "\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */