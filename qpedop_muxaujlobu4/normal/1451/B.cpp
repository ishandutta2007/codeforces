#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
typedef long long ll;
using namespace std;
long long gcd(long long i, long long j) {
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
const long long INF = 1e9;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1070100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l;
            string s1 = "", s2="";
            for (int i = l; i < r; ++i) {
                s1.push_back(s[i]);
            }
            int sz = r - l;
            bool v = false;
            for (int i = 0; i < sz - 1; ++i) {
                int j = 0;
                bool v1 = true;
                for (int tt = 0; tt < sz; ++tt) {
                    char x = s1[tt];
                    while (j < n && x != s[j])++j;
                    if (j >= n) {
                        v1 = false;
                        break;
                    }
                    if (tt == i) {
                        j += 2;
                    }
                    else {
                        ++j;
                    }
                }
                if (v1) {
                    v = true;
                    break;
                }
            }
            if (v)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}