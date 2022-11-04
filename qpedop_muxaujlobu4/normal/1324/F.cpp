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
using namespace std;
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const double e = 0.0000005;
const double pi = 3.14159265359;
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
long long arr[200001];
long long Cw[200001];
long long ans[200001];
vector<int>Ed[200001];
void dfs(int i, int p) {
    for (auto x : Ed[i]) {
        if (x == p)continue;
        dfs(x, i);
        if (ans[x] > 0)ans[i] += ans[x];
    }
}
void dfs2(int i, int p) {
    for (auto x : Ed[i]) {
        if (x == p)continue;
        if (ans[i] > 0) {
            if (ans[x] < 0) ans[x] = ans[x] + ans[i];
            else ans[x] = max(ans[x], ans[i]);
        }
        dfs2(x, i);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        ans[i] = arr[i];
        if (!ans[i]) {
            --arr[i];
            --ans[i];
        }
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        Ed[a].push_back(b);
        Ed[b].push_back(a);
    }
    dfs(1, -1);

    dfs2(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */