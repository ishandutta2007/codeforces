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
#include<bitset>
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
const long long INF = 10000000000000;
const int Y = 100001;
int IDX[3 * Y + 1];
int arr[3 * Y];
int team[Y][3];
int way[3 * Y];
int IDX2[3 * Y];
int main()
{
    srand(10241274216);
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n;
    for (int i = 1; i <= 3 * n; ++i) {
        int tmp;
        cin >> tmp;
        IDX2[tmp] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> team[i][j];
            way[3 * i - j] = team[i][j];
            IDX[team[i][j]] = 3 * i - j;
        }
    }
    cin >> k;
    int L = -1;
    int to = IDX[k];
    if (to % 3 == 2) {
        ++to;
    }
    else {
        if (to % 3 == 1)to += 2;
    }
    int mn = IDX2[k],mn1 = IDX2[k];
    int mx = 0;
    for (int j = 0; j <= 2; ++j) {
        if (way[to - j] != k)mx = max(mx, way[to - j]);
        mn = min(mn, IDX2[way[to - j]]);
    }
    if (mn != mn1) {
        for (int i = 1; i <= 3 * n; ++i) {
            if (i != k)cout << i << " ";
        }
        return 0;
    }
    for (int i = 1; i <= to; ++i) {
        if (way[i] <= mx) {
            arr[++L] = way[i];
        }
    }
    ++L;
    sort(arr, arr + L);
    int last = L;
    for (int i = 1; i <= 3 * n; ++i) {
        if (way[i]>mx || i >to) {
            arr[last++] = way[i];
        }
    }
    sort(arr + L, arr + last);
    for (int i = 0; i <= 3 * n; ++i) {
        if (arr[i] != k && arr[i]!=0) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */

    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);