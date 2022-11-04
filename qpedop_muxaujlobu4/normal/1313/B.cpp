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
        int n, x, y;
        cin >> n >> x >> y;
        if (x + y < n + 1) {
            cout << 1 << " " << x + y - 1 << "\n";
        }
        else {
            if (x + y == n + 1) {
                cout << min(n,2) << " " << n << "\n";
            }
            else {
                if (x + y + 1 == 2 * n || x + y == 2 * n) {
                    cout << n << " " << n << "\n";
                }
                else {
                    int tmp = (x + y + 1);
                    int tmp1 = tmp - n;
                    int tmp2 = n - tmp1 + 1;
                    if (x >= tmp1 || y >= tmp1)--tmp2;
                    cout << n - tmp2 << " " << n << "\n";
                }
            }
        }
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */