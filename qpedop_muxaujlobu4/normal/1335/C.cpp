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
#include<ctime>
#include<bitset>
#include<random>
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
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 200100;
const int INF = 100000000;
const long long m = 998244353;
int arr[Y];
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
        int n, mm = 0, c1 = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)arr[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int tmp;
            cin >> tmp;
            ++arr[tmp];
            if (arr[tmp] == 1)++c1;
            mm = max(mm, arr[tmp]);
        }
        int r1 = min(mm - 1, c1);
        int r2 = min(mm, c1 - 1);
        int res = n / 2;
        res = min(res, max(r1, r2));
        cout << res << "\n";
    }
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/