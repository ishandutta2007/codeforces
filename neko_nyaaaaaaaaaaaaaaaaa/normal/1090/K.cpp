#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
struct chash {
    int operator()(array<bool, 26> x) const {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res = hash_combine(res, hash_f(x[i]));
        }
        return res;
    }
};
const int MAXN = 1e5 + 5;
int N;
string S[MAXN], T[MAXN];
gp_hash_table<array<bool, 26>, vector<int>, chash> cnts;
vector<vector<int>> groups;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    for (int i = 0; i < N; i++) {
        array<bool, 26> counts = {0};
        for (auto j : T[i]) {
            counts[j - 'a'] = true;
        }
        string newS;
        bool found = false;
        for (int j = S[i].size() - 1; j >= 0; j--) {
            if (!counts[S[i][j] - 'a']) {
                found = true;
            }
            if (found)
                newS.push_back(S[i][j]);
        }
        reverse(newS.begin(), newS.end());
        S[i] = newS;
        cnts[counts].push_back(i);
    }
    for (auto i : cnts) {
        gp_hash_table<string, vector<int>> cur;
        for (auto j : i.second) {
            cur[S[j]].push_back(j);
        }
        for (auto j : cur) {
            vector<int> t = j.second;
            groups.push_back(t);
        }
    }
    cout << groups.size() << endl;
    for (auto i : groups) {
        cout << i.size();
        for (auto j : i) {
            cout << ' ' << j + 1;
        }
        cout << endl;
    }
}