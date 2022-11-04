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
    vector<int>s(n);
    for (auto& x : s) {
        cin >> x;
        for (int i = 0; i < 32; ++i) {
            if (x & (1 << i))ct[i]++;
        }
    }
    int g = -1;
    for (int i = 31; i >= 0; --i)if (ct[i] == 1) {
        g = i;
        break;
    }
    if (g != -1) {
        for (int i = 0; i < n; ++i) {
            if (s[i] & (1 << g)) {
                int tmp = s[i];
                s[i] = s[0];
                s[0] = tmp;
                break;
            }
        }
    }
    for (auto x : s)cout << x << " ";
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */