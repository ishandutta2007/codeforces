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
typedef unsigned long long ull;
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
const int maxN = 301, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
  //  file_inc();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int>mp;
        vector<int>a;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            if (a.empty() || a.back() != v)a.push_back(v);
        }
        for (auto x : a) {
            ++mp[x];
        }
        --mp[a[0]];
        --mp[a.back()];
        int ans = INF;
        for (auto x : mp) {
            ans = min(ans, x.second + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}