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
char Mat[9][9];
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
        vector<pair<int, int>>pp;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> Mat[i][j];
                if (Mat[i][j] == '1')Mat[i][j] = '2';
            }
        }
        for (int i = 0; i <= 8; ++i) {
            for (int j = 0; j <= 8; ++j) {
                cout << Mat[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/