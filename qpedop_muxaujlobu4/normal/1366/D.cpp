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
const long long INF = 100000000;
const int Y = 200100;
//const long long m = 1000000007;
bool sim[4000];
string gt(int a) {
    vector<int> tmp;
    while (a) {
        tmp.push_back(a % 10);
        a /= 10;
    }
    string ad = "";
    for (int i = (int)tmp.size() - 1; i >= 0; --i) {
        ad.push_back('0' + tmp[i]);
    }
    return ad;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a1 = "", a2 = "";
    vector<int>sm;
    for (int i = 2; i < 4000; ++i) {
        if (!sim[i]) {
            sm.push_back(i);
            for (int j = i + i; j < 4000; j += i)sim[j] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int dl = -1;
        int v;
        cin >> v;
        for (auto x : sm) {
            if (v % x == 0) {
                dl = x;
                break;
            }
        }
        int st = 1;
        if (dl == -1) {
            a1 += "-1 ";
            a2 += "-1 ";
        }
        else {
            while (v % dl == 0) {
                st *= dl;
                v /= dl;
            }
            if (v == 1) {
                a1 += "-1 ";
                a2 += "-1 ";
            }
            else {
                a1 += gt(dl) + " ";
                a2 += gt(v) + " ";
            }
        }
    }
    cout << a1 << "\n" << a2;
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