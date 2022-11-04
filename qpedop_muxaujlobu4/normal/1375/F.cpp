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
using namespace std;
int gcd(int i, int j) {
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
long long INF = 1e17;
const long long m = 1000000007;
const int Y = 1001;
bool MT[Y][Y];
vector<pair<int, int>>pr;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long a, b, c;
    cin >> a >> b >> c;
    int cc = 0;
    cout << "First" << endl;
    while (true) {
        if (cc == 0) {
            vector<long long>aa;
            aa.push_back(a);
            aa.push_back(b);
            aa.push_back(c);
            sort(aa.begin(), aa.end());
            long long y = 2 * (aa[2] - aa[1]) + aa[1] - aa[0];
            cout << y << endl;
            int h;
            cin >> h;
            if (h == 0)return 0;
            if (h == 1) {
                a += y;
            }
            else {
                if (h == 2) {
                    b += y;
                }
                else {
                    c += y;
                }
            }
        }
        else {
            vector<long long>aa;
            aa.push_back(a);
            aa.push_back(b);
            aa.push_back(c);
            sort(aa.begin(), aa.end());
            long long y = 2 * (aa[2] - aa[1]) + aa[1] - aa[0];
            if (aa[2] - aa[1] == aa[1] - aa[0])y = aa[2] - aa[1];
            cout << y << endl;
            int h;
            cin >> h;
            if (h == 0)return 0;
            if (h == 1) {
                a += y;
            }
            else {
                if (h == 2) {
                    b += y;
                }
                else {
                    c += y;
                }
            }
        }
        ++cc;
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */