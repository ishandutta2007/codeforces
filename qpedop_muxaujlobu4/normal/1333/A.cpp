
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
const int Y = 1000;
const int INF = 1000000;
char Mat[Y + 1][Y + 1];
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
        int n, m;
        cin >> n >> m;
        if (n == 2) {
            if (m == 2) {
                Mat[0][1] = Mat[0][0] = Mat[1][1] = 'B';
                Mat[1][0] = 'W';
            }
            else {
                for (int i = 0; i < m; ++i) {
                    Mat[0][i] = 'W';
                    Mat[1][i] = 'B';
                }
                Mat[0][0] = 'B';
            }
        }
        else {
            Mat[0][0] = Mat[1][1] = 'B';
            Mat[1][0] = Mat[0][1] = 'W';
            for (int i = 2; i < m; ++i) {
                Mat[0][i] = 'W';
                Mat[1][i] = 'B';
            }
            for (int i = 2; i < n; ++i) {
                for (int j = 0; j < m; ++j)Mat[i][j] = 'B';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)cout << Mat[i][j];
            cout << "\n";
        }
    }
    return 0;
}