#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
#include <array>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

const ll INF = 1e18;
const int maxN = 200001;

int dsu[100001], dsu2[100001];
int n;

void init_dsu() {
    range(i, n + 1) {
        dsu[i] = i;
        dsu2[i] = i;
    }
}

int get_dsu (int a) {
    return (dsu[a] == a) ? a : dsu[a] = get_dsu(dsu[a]);
}

bool Unio(int a, int b) {
    a = get_dsu(a);
    b = get_dsu(b);
    if (rand() % 2) {
        swap(a, b);
    }
    dsu[a] = b;
    return a == b;
}

int get_dsu2(int a) {
    return (dsu2[a] == a) ? a : dsu2[a] = get_dsu2(dsu2[a]);
}
bool Unio2(int a, int b) {
    a = get_dsu2(a);
    b = get_dsu2(b);
    if (rand() % 2) {
        swap(a, b);
    }
    dsu2[a] = b;
    return a == b;
}

void solve() {
    cin >> n;
    init_dsu();
    vector<pair<int, pair<int, int>>> s, s2;
    vector<int> ans1(n, 0);
    vector<int> ans2(n, 0);
    range(i, n) {
        int sa, ea, sb, eb; cin >> sa >> ea >> sb >> eb;
        s.push_back({sa, {-1, i}});
        s.push_back({ea, {1, i}});
        s2.push_back({sb, {-1, i}});
        s2.push_back({eb, {1, i}});
    }
    sort(all(s)); sort(all(s2));
    set<int> current;
    int u = 1, p = 0;
    range(i, n * 2) {
        if (s[i].second.first == -1) {
            p++;
            if (!current.empty()) {
                Unio(s[i].second.second, *current.begin());
            }
            ans1[s[i].second.second] = -u;
            current.insert(s[i].second.second);
        } else {
            u++;
            current.erase(s[i].second.second);
            //cout << s[i].second.second << '\n';
            ans1[s[i].second.second] += p;
            //cout << ans1[s[i].second.second] << '\n';
        }
    }
    u = 1; p = 0;
    range(i, n * 2) {
        if (s2[i].second.first == -1) {
            p++;
            if (!current.empty()) {
                Unio2(s2[i].second.second, *current.begin());
            }
            ans2[s2[i].second.second] = -u;
            current.insert(s2[i].second.second);
        } else {
            u++;
            current.erase(s2[i].second.second);
            ans2[s2[i].second.second] += p;
        }
    }
    vector<set<int>> dsu11(n), dsu22(n);
    range(i, n) {
        //cout << i << ' ' << ans1[i] << ' ' << ans2[i] << '\n';
        if (ans1[i] != ans2[i]) {
            cout << "NO";
            return;
        }
        //cout << i << ' ' << get_dsu(i) << '\n';
        dsu11[get_dsu(i)].insert(i);
        dsu22[get_dsu2(i)].insert(i);
    }
    /*
    range(i, n) {
        for (auto x: dsu11[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << "DSSD\n";
    range(i, n) {
        for(auto x: dsu22[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }*/
    vector<int> used(n, 0), used2(n, 0);
    range(i, n) {
        if (dsu11[get_dsu(i)].size() != dsu22[get_dsu2(i)].size()) {
            cout << "NO";
            return;
        }
        auto it = dsu11[get_dsu(i)].begin();
        auto it2 = dsu22[get_dsu2(i)].begin();
        if (used[get_dsu(i)] != used2[get_dsu2(i)]) {
            cout << "NO";
            return;
        }
        if (used2[get_dsu2(i)] == 1) {
            continue;
        }
        used[get_dsu(i)] = 1;
        used2[get_dsu2(i)] = 1;
        while(it != dsu11[get_dsu(i)].end()) {
            if (*it != *it2) {
                cout << "NO";
                return;
            }
            it++;
            it2++;
        }
    }
    cout << "YES";
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int tests;
    //cin >> tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}