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
const int Y = 200100;
const long long m = 1000000007;
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
long long arr[Y];
bool cmp(long long a, long long b) {
    return a % 2 < b % 2;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        long long s = 0, tmp = 0;
        for (int i = 0; i < n; ++i) {
            if (tmp > 0 && arr[i] > 0) {
                tmp = max(tmp, arr[i]);
            }
            else {
                if (tmp < 0 && arr[i] < 0) {
                    tmp = max(tmp, arr[i]);
                }
                else {
                    s += tmp;
                    tmp = arr[i];
                }
            }
        }
        s += tmp;
        cout << s << "\n";
    }
    return 0;
}