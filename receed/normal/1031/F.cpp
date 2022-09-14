#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 2000;
const ll M = 1e12;
int isp[N];
ll mdc, mpos;
vector<int> p, repr;
map<vector<int>, int> num;
vector<ll> vdc;
map<ll, int> vc;

void go(int pos, ll x, int d, ll dc) {
    //cout << x << ' ' << dc << "!\n";
    if (x > M)
        return;
    if (!vc.count(dc)) {
        int sz = vc.size();
        vc[dc] = sz;
    }
    num[repr] = vdc.size();
    vdc.push_back(vc[dc]);
    repr.emplace_back();
    for (int i = 1; i <= d; i++) {
        x *= p[pos];
        if (x > M)
            break;
        repr[pos] = i;
        go(pos + 1, x, i, dc * (i + 1));
    }
    repr.pop_back();
}

vector<int> conv(int x) {
    vector<int> cc;
    for (int i = 0; p[i] * p[i] <= x; i++) {
        if (x % p[i])
            continue;
        cc.emplace_back();
        while (x % p[i] == 0) {
            x /= p[i];
            cc.back()++;
        }
    }
    if (x > 1)
        cc.push_back(1);
    sort(cc.rbegin(), cc.rend());
    return cc;
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 2; i < N; i++) {
        if (isp[i])
            continue;
        p.push_back(i);
        for (int j = i * 2; j < N; j += i)
            isp[j] = 1;
    }
    go(0, 1, 100, 1);
    //cout << sd.size() << ' '<< mdc << ' ' << s.size() << "!\n";
    vector<vector<int>> md(num.size(), vector<int>(vc.size(), 1000));
    //cout << num.size() << '\n';
    for (auto i1 = num.begin(); i1 != num.end(); i1++) {
        auto p1 = *i1;
        /*for (int i : p1.first)
            cout << i << ' ';
        cout << vdc[p1.second] << "!!\n";*/
        for (auto i2 = i1; i2 != num.end(); i2++) {
            auto p2 = *i2;
            int d = 0;
            for (int i = 0; i < max(p1.first.size(), p2.first.size()); i++)
                d += abs((i < p1.first.size() ? p1.first[i] : 0) - (i < p2.first.size() ? p2.first[i] : 0));
            md[p1.second][vdc[p2.second]] = min(md[p1.second][vdc[p2.second]], d);
            md[p2.second][vdc[p1.second]] = min(md[p2.second][vdc[p1.second]], d);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        int ans = 1000;
        int vx = num[conv(x)], vy = num[conv(y)];
        for (int j = 0; j < vc.size(); j++)
            ans = min(ans, md[vx][j] + md[vy][j]);
        cout << ans << '\n';
    }
}