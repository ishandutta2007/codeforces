#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 10000000000000000;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const long long m = 1000000007;
const int Y = 100000;
long long arr[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int h = 0; h < t; ++h) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a >= 4 && b >= 4 && c >= 4) {
            cout << 7 << "\n";
            continue;
        }
        else {
            if (a == 2 && b == 2 && c >= 3 || b == 2 && c == 2 && a >= 3 || a == 2 && c == 2 && b >= 3) {
                cout << 5 << "\n";
                continue;
            }
            else
            {
                int ans = 0;
                if (c != 0) {
                    ++ans;
                    c -= 1;
                }
                if (b != 0) {
                    ++ans;
                    --b;
                }
                if (a != 0) {
                    ++ans;
                    --a;
                }
                if (b != 0 && a != 0) {
                    ++ans;
                    --b;
                    --a;
                }
                if (c != 0 && a != 0) {
                    ++ans;
                    --c;
                    --a;
                }
                if (b != 0 && c != 0) {
                    ++ans;
                    --b;
                    --c;
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */