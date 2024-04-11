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
long long arr[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        int len = a.length();
        bool  ans = true;
        for (int j = 0; j < len; ++j) {
            if (c[j] != a[j] && c[j] != b[j])ans = false;
        }
        if (ans)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */