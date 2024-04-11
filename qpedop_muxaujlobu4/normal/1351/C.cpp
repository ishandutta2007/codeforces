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
#include<random>
using namespace std;
const unsigned long long INF = 1e17;
const int INFi = 2e8;
const int Y = 200100;
const long long m = 998244353;
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
struct PT {
    int x;
    int y;
    PT(int X = 0, int FY = 0) {
        x = X;
        y = FY;
    }
};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);

    int t;
    cin >> t;
    while (t--) {
        map<pair<pair<int, int>, pair<int, int>>, bool>sb;
        string s;
        cin >> s;
        int ans = 0;
        pair<int, int> N = { 0,0 };
        for (auto x : s) {
            pair<int, int> D;
            if (x == 'N') {
                D = { N.first + 1, N.second };
            }
            if (x == 'S') {
                D = { N.first - 1, N.second };
            }
            if (x == 'W') {
                D = { N.first, N.second + 1 };
            }
            if (x == 'E') {
                D = { N.first, N.second - 1 };
            }
            if (sb[{N, D}] || sb[{D, N}]) {
                ++ans;
            }
            else {
                ans += 5;
                sb[{N, D}] = true;
                sb[{D, N}] = true;
            }
            N = D;
        }
        cout << ans << endl;
    }
    return 0;
}