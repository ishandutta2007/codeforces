#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
//#define int short
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
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
const long long INF = 2e17;
const long long m = 1000000007;
const int Y = 200101;
int arr[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        c1 -= arr[tmp] / 4;
        c2 -= arr[tmp] / 2;
        arr[tmp]++;
        c1 += arr[tmp] / 4;
        c2 += arr[tmp] / 2;
    }
    int q;
    cin >> q;
    while (q--) {
        char tp;
        int tmp;
        cin >> tp >> tmp;
        c1 -= arr[tmp] / 4;
        c2 -= arr[tmp] / 2;
        if (tp == '+')arr[tmp]++;
        else arr[tmp]--;
        c1 += arr[tmp] / 4;
        c2 += arr[tmp] / 2;
        if (c1 != 0 && c2 >= 4)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}