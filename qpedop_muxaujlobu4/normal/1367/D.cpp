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
const long long INF = 10000000;
const int Y = 200100;
const long long mod = 1000000007;
bool sm(vector<int>aa) {
    int s = 0;
    for (auto x : aa)s += x;
    return s != 0;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int>bk(26);
        for (auto x : s)++bk[x - 'a'];
        int n;
        cin >> n;
        vector<int>b(n);
        vector<int>vs(n, 0);
        vector<char>ans(n);
        for (auto& x : b)cin >> x;
        int sss = 0;
        while (sss != n) {
            vector<int>id;
            for (int i = 0; i < n; ++i) {
                if (b[i] == 0 && vs[i] == 0) {
                    id.push_back(i);
                    vs[i] = 1;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (vs[i] == 0) {
                    for (auto x : id) {
                        b[i] -= abs(x - i);
                    }
                }
            }
            char p;
            for (int j = 25; j >= 0; --j) {
                if (bk[j] != 0) {
                    if (bk[j] >= id.size()) {
                        p = 'a' + j;
                        bk[j] = 0;
                        break;
                    }
                    bk[j] = 0;
                }
            }
            for (auto x : id) {
                ans[x] = p;
            }
            sss += id.size();
        }
        for (auto x : ans)cout << x;
        cout << endl;
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