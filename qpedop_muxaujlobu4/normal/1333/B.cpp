
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<random>
#include<iostream>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 100000;
const int INF = 1000000;
int arr[Y + 1];
int arrb[Y + 1];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool res = true;
        bool pl = false;
        bool mn = false;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> arrb[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (arrb[i] > arr[i]) {
                if (pl == false)res = false;
            }
            if (arrb[i] < arr[i]) {
                if (mn == false)res = false;
            }
            if (arr[i] == 1)pl = true;
            if (arr[i] == -1)mn = true;
        }
        if (res)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}