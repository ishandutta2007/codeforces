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

ll ans;

int get(int p, vector<int> &f) {
    int res = 0;
    for (int i = p; i > 0; i &= i - 1)
        res += f[i];
    return res;
}

void add(int p, vector<int> &f) {
    for (int i = p; i + 1 < f.size(); i |= i + 1)
        f[i + 1]++;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("wikipidia.in", "r", stdin); 
    //freopen("wikipidia.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(3));
    vector<int> lq;
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
        lq.push_back(a[i][2]);
    }
    sort(lq.begin(), lq.end());
    lq.resize(unique(lq.begin(), lq.end()) - lq.begin());
    vector<vector<int>> ls(lq.size()), f(lq.size());
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++)
        ls[lower_bound(lq.begin(), lq.end(), a[i][2]) - lq.begin()].push_back(a[i][1]);
    for (int i = 0; i < lq.size(); i++) {
        sort(ls[i].begin(), ls[i].end());
        f[i].assign(ls[i].size() + 1, 0);
    }
    for (auto &pp : a) {
        int pos = lower_bound(lq.begin(), lq.end(), pp[2]) - lq.begin(), lp = pos;
        while (lp > 0 && lq[pos] - lq[lp - 1] <= k)
            lp--;
        for (int i = lp; i < lq.size() && lq[i] - lq[pos] <= k; i++) {
            int cl = lower_bound(ls[i].begin(), ls[i].end(), pp[1] - pp[0]) - ls[i].begin();
            int cr = upper_bound(ls[i].begin(), ls[i].end(), pp[1] + pp[0]) - ls[i].begin();
            if (cl < cr)
                ans += get(cr, f[i]) - get(cl, f[i]);
        }
        add(lower_bound(ls[pos].begin(), ls[pos].end(), pp[1]) - ls[pos].begin(), f[pos]);
    }
    cout << ans;
}