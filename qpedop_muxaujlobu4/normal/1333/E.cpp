
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
const int Y = 500;
const int INF = 1000000;
int Mat[Y + 1][Y + 1];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << -1;
        return 0;
    }
    int f = n * n;
    Mat[0][1] = f;
    Mat[0][0] = f - 6;
    Mat[0][2] = f - 7;
    Mat[1][0] = f - 4;
    Mat[1][1] = f - 8;
    Mat[1][2] = f - 5;
    Mat[2][0] = f - 1;
    Mat[2][1] = f - 2;
    Mat[2][2] = f - 3;
    if (n == 3) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)cout << Mat[i][j] << " ";
            cout << "\n";
        }
        return 0;
    }
    int st = 1;
    for (int i = 3; i < n; ++i) {
        Mat[i][0] = st++;
    }
    for (int i = n - 1; i >= 3; --i) {
        Mat[i][1] = st++;
    }
    for (int i = 3; i < n; ++i) {
        Mat[i][2] = st++;
    }
    for (int j = 3; j < n; ++j) {
        if (j % 2 == 1) {
            for (int i = n - 1; i >= 0; --i) {
                Mat[i][j] = st++;
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                Mat[i][j] = st++;
            }
        }
    }
    if (n % 2 == 0) {
        swap(Mat[0][n - 1], Mat[1][n - 1]);
    }
    else {
        swap(Mat[n - 1][n - 1], Mat[1][n - 1]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)cout << Mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}