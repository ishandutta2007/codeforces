#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 101;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '@')
            pos.push_back(i);
    }

    if (pos.empty() or pos.front() == 0 or pos.back() == n - 1) {
        cout << "No solution\n";
        return 0;
    }

    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] - pos[i-1] <= 2) {
            cout << "No solution\n";
            return 0;
        }
    }

    string temp;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (pos.back() == i) {
            cout << temp;
            for (int j = i; j < n; j++) cout << s[j];
            return 0;
        }

        if (s[i] == '@')
            flag = true;
        temp += s[i];

        if (s[i] != '@' and flag) {
            cout << temp << ",";
            temp.clear();
            flag = false;
        }
    }
    return 0;
}