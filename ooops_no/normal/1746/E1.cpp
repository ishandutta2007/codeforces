#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int number = -1;
bool last = 1;

bool ask(vector<int> a) {
    cout << "? " << a.size() << ' ';
    for (auto to : a) {
        cout << to << ' ';
    }
    cout << endl;
    string s;
    cin >> s;
    return (s == "YES" ? 1 : 0);
}

map<vector<bool>, vector<int>> ans;

void func() {
    int K = 4;
    ans.clear();
    vector<int> arr{1, 2, 2, 1};
    for (int i = 0; i < (1 << K); i++) {
        vector<bool> res;
        for (int j = 0; j < K; j++) {
            if (i & (1 << j)) {
                res.pb(1);
            } else {
                res.pb(0);
            }
        }
        for (int in = 1; in <= 3; in++) {
            vector<int> mas;
            for (int j = 0; j < K; j++) {
                if ((in == arr[j]) == (bool)(i & (1 << j))) {
                    mas.pb(1);
                } else {
                    mas.pb(0);
                }
            }
            bool good = 1;
            for (int j = 0; j + 1 < K; j++) {
                if (mas[j] + mas[j + 1] == 0) {
                    good = 0;
                }
            }
            if (good) {
                ans[res].pb(in);
            }
        }
    }
}

vector<int> sum(vector<int> a, vector<int> b) {
    vector<int> c;
    for (auto to : a) {
        c.pb(to);
    }
    for (auto to : b) {
        c.pb(to);
    }
    return c;
}

signed main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    func();
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    last = 1;
    while (a.size() >= 1) {
        n = a.size();
        if (a.size() <= 3) {
            if (a.size() == 1) {
                cout << "! " << a[0] << endl;
                break;
            }
            vector<bool> arr{ask({a[0]}), ask({a[1]}), ask({a[1]}), ask({a[0]})};
            auto mas = ans[arr];
            cout << "! " << a[mas[0] - 1] << endl;
            string s;
            cin >> s;
            if (s == ":(") {
                cout << "! " << a[mas[1] - 1] << endl;
                cin >> s;
            }
            break;
        } else {
            vector<vector<int>> mas(4);
            for (int i = 0; i < n; i++) {
                mas[i % 4].pb(a[i]);
            }
            auto res1 = ask(sum(mas[0], mas[1])), res2 = ask(sum(mas[0], mas[2]));
            int del = -1;
            if (res1 && res2) {
                del = 3;
            } else if (!res1 && !res2) {
                del = 0;
            } else if (!res1) {
                del = 1;
            } else {
                del = 2;
            }
            a.clear();
            for (int i = 0; i < 4; i++) {
                if (i == del) continue;
                for (auto to : mas[i]) {
                    a.pb(to);
                }
            }
        }
    }
    return 0;
}