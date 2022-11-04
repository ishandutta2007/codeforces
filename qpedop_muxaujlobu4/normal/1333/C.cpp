
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
const int Y = 200000;
const int INF = 1000000;
long long arr[Y + 1];
map<long long, bool>qq;
map<long long, int>q;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int n;
    cin >> n;
    long long ans = 0;
    qq[0] = true;
    q[0] = 0;
    long long ss = 0;
    int id = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        ss += arr[i];
        if (qq[ss]) {
            int ti = q[ss];
            ans += i - (ti + 1);
            qq.clear();
            id = ti + 2;
            ss = 0;
            qq[0] = true;
            q[0] = id - 1;
            for (int j = id; j <= i; ++j) {
                ss += arr[j];
                qq[ss] = true;
                q[ss] = j;
            }
        }
        else {
            ans += i - id + 1;
            qq[ss] = true;
            q[ss] = i;
        }
    }
    cout << ans;
    return 0;
}