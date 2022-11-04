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
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const double e = 0.0000005;
const double pi = 3.14159265359;
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
long long arr[200000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        arr[i] -= tmp;
    }
    sort(arr, arr + n);
    long long ans = 0;
    long long st = 0;
    for (long long i = 1; i < n; ++i) {
        if (arr[i] <= 0)continue;
        long long b = -1, p = i;
        while (b + 1 != p) {
            long long mid = (b + p) / 2;
            if (arr[mid] + arr[i] > 0) {
                p = mid;
            }
            else {
                b = mid;
            }
        }
        ans += i - p;
    }
    cout << ans;
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */