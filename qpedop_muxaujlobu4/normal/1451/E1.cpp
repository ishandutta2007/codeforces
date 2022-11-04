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
int qw(int i, int j, string tp) {
    int res;
    cout << tp << " " << i << " " << j << endl;
    cin >> res;
    return res;
}
vector<int>sq(16);
void add_to_sq(int v, int j) {
    for (int i = 0; i < 16; ++i) {
        if ((v & (1 << i)) != 0)sq[i] |= 1 << j;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>ans(n);
    add_to_sq(qw(1, 2, "AND"), 0);
    add_to_sq(qw(1, 2, "OR"), 1);
    add_to_sq(qw(2, 3, "AND"), 2);
    add_to_sq(qw(2, 3, "OR"), 3);
    add_to_sq(qw(1, 3, "AND"), 4);
    for (int i = 0; i < 16; ++i) {
        if (sq[i] == 0) {

        }
        if (sq[i] == 8) {
            ans[2] |= 1 << i;
        }
        if (sq[i] == 10) {
            ans[1] |= 1 << i;
        }
        if (sq[i] == 14) {
            ans[2] |= 1 << i;
            ans[1] |= 1 << i;
        }
        if (sq[i] == 2) {
            ans[0] |= 1 << i;
        }
        if (sq[i] == 26) {
            ans[2] |= 1 << i;
            ans[0] |= 1 << i;
        }
        if (sq[i] == 11) {
            ans[0] |= 1 << i;
            ans[1] |= 1 << i;
        }
        if (sq[i] == 31) {
            ans[2] |= 1 << i;
            ans[1] |= 1 << i;
            ans[0] |= 1 << i;
        }
    }
    for (int i = 3; i < n; ++i) {
        int r = qw(1, i + 1, "XOR");
        ans[i] = ans[0] ^ r;
    }
    cout << "! ";
    for (auto x : ans)cout << x << " ";
    return 0;
}