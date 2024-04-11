#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    queue<int> q1, q2;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'D')
            q1.push(i);
        else q2.push(i);
    }

    while (!q1.empty() and !q2.empty()) {
        if (q1.front() < q2.front()) {
            q2.pop();
            q1.push(q1.front() + n);
            q1.pop();
        }
        else {
            q1.pop();
            q2.push(q2.front() + n);
            q2.pop();
        }
    }

    if (q1.empty()) {
        cout << "R";
        return 0;
    }
    cout << "D";
    return 0;
}