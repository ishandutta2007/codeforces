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
vector<string> decd;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>ans(n);
    for (int i = 1; i < n; ++i)ans[i] = qw(1, i + 1, "XOR");
    map<int, int>mp;
    int i1 = -1, i2 = -1;
    for (int i = 0; i < n; ++i) {
        if (mp.count(ans[i])) {
            i1 = mp[ans[i]];
            i2 = i;
        }
        else mp[ans[i]] = i;
    }
    if (i1 == -1) 
    {
        int v1 = -1, v2=-1;
        for (int i = 1; i < n; ++i) {
            if (ans[i] == 1)v1 = i;
            if (ans[i] == n - 2)v2 = i;
        }
        int r1 = qw(1, v1 + 1, "AND");
        int r2 = qw(1, v2 + 1, "AND");
        swap(r1, r2);
        if (r1 % 2 == 1)ans[0] |= 1;
        for (int i = 1; i < 16; ++i) {
            bool f = (r2 & (1 << i)) != 0;
            if (f)ans[0] |= 1 << i;
        }
        cout << "! " << ans[0] << " ";
        for (int i = 1; i < n; ++i)cout << (ans[i] ^ ans[0]) << " ";
        cout << endl;
    }
    else {
        vector<int>aa1(n);
        aa1[i1] = aa1[i2] = qw(i1 + 1, i2 + 1, "AND");
        if (i1 != 0) {
            aa1[0] = aa1[i1] ^ ans[i1];
        }
        for (int i = 1; i < n; ++i)aa1[i] = aa1[0] ^ ans[i];
        cout << "! ";
        for (auto x : aa1)cout << x << " ";
        cout << endl;
    }
    return 0;
}