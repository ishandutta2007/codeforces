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
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>

void boostIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const int Y = 200100;
const long long m = 998244353;
template<typename T> T getint() {
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
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
bool simple[Y];
int dg[Y];
int main()
{
    boostIO();
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto& x : a)cin >> x;
    if (n == 2) {
        cout << (long long)a[0] * a[1] / gcd(max(a[0], a[1]), min(a[0], a[1]));
        return 0;
    }
    vector<int>dg(Y);
    vector<vector<int>>sb;
    vector<int>sim;
    for (int i = 2; i < 500; ++i) {
        if (simple[i] == false) {
            sim.push_back(i);
            sb.push_back({});
            for (int j = i + i; j < Y; j += i)
                simple[j] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sim.size(); ++j) {
            sb[j].push_back(0);
            while (a[i] % sim[j] == 0) {
                a[i] /= sim[j];
                sb[j].back()++;
            }
        }
    }
    long long res = 1;
    int cl = 0, w = max(a[0], a[1]);
    for (auto x : a) {
        if (x == w)++cl;
    }
    if (cl + 1 >= n)res = w;
    for (auto & x : sb)sort(x.begin(), x.end());
    for (int j = 0; j < sim.size(); ++j) {
        int tmp = sim[j];
        for (int i = 0; i < sb[j][1]; ++i) {
            res *= tmp;
        }
    }
    cout << res;
    return 0;
}