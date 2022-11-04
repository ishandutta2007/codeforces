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
map<int, vector<int>>mp;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int>vd;
    while (t--) {
        mp.clear();
        int n;
        cin >> n;
        vector<pair<int, int>>ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i].first;
            ar[i].second = i;
        }
        sort(ar.begin(), ar.end());
        vector<int>vals;
        vals.push_back(ar[0].first);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (ar[i].first != vals.back())vals.push_back(ar[i].first);
            mp[ar[i].first].push_back(ar[i].second);
        }
        if (vals.size() == 1) {
            vd.push_back(0);
            continue;
        }
        for (int i = 0; i < vals.size();) {
            int sm = mp[vals[i]].size();
            int j = i + 1;
            for (; j < vals.size(); ++j) {
                if (mp[vals[j]][0] < mp[vals[j - 1]].back()) {
                    break;
                }
                else {
                    sm += mp[vals[j]].size();
                }
            }
            if (j != vals.size()) {
                vector<int>bb = mp[vals[j]];
                int vr = mp[vals[j - 1]].back();
                sm += bb.end() - lower_bound(bb.begin(), bb.end(), vr);
            }
            if (i != 0) {
                vector<int>bb = mp[vals[i - 1]];
                int vr = mp[vals[i]][0];
                sm += lower_bound(bb.begin(), bb.end(), vr) - bb.begin();
            }
            i = j;
            ans = max(ans, sm);
        }
        for (int i = 0; i < vals.size() - 1; ++i) {
            vector<int>bb = mp[vals[i]];
            vector<int>df = mp[vals[i + 1]];
            int j1 = 0;
            for (int j = 0; j < bb.size(); ++j) {
                while (j1 != df.size() && df[j1] < bb[j])++j1;
                int tmp = j + 1 + df.size() - j1;
                ans = max(ans, tmp);
            }
        }
        vd.push_back(n - ans);
    }
    for (auto x : vd)cout << x << "\n";
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