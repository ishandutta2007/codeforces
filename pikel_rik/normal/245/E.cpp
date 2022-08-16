#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int c = 0, ans = 0, max_ = 0, min_ = 0;
    for (char i : s) {
        if (i == '+')
            c += 1;
        else c -= 1;
        if (c > max_)
            max_ = c;
        else if (c < min_)
            min_ = c;
        ans = max(ans, max_ - min_);
    }
    cout << ans;
    return 0;
}