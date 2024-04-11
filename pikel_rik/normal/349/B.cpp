#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

vi digit(10);

int dp[1000001];
int ans[1000001];

int recurse(int i) {
    if (i < 0)
        return -1;
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int sum = -1, best = -1;
    for (int j = 1; j < 10; j++) {
        if (sum <= recurse(i - digit[j]) and recurse(i - digit[j]) != -1) {
            sum = recurse(i - digit[j]);
            best = j;
        }
    }
    ans[i] = best;
    return dp[i] = sum + 1;
}

int main() {
    ios::sync_with_stdio(false);

    int v;
    cin >> v;

    memset(dp, -1, sizeof(dp));
    memset(ans, -1, sizeof(ans));

    for (int i = 1; i <= 9; ++i) cin >> digit[i];

    if (v < *min_element(digit.begin() + 1, digit.end()))
        cout << "-1\n";
    else {
        recurse(v);

        string s;
        while (ans[v] > 0) {
            s.push_back(ans[v] + '0');
            v -= digit[ans[v]];
        }

//        sort(all(s));
//        reverse(all(s));

        cout << s << "\n";
    }
    return 0;
}