#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

vi a;
int choice[21][11][1001];
pi ans;

bool flag = false;
int n;

void recurse(int i, int j, int k) {
    if (flag)
        return;
    if (k != 1 and ((n != 1 and abs(i) >= 10) or (k % 2 == 0 and i <= 0) or (k % 2 != 0 and i >= 0)))
        return;
    if (k == n + 1) {
        ans = {i, j};
        flag = true;
        return;
    }
    if (choice[i + 10][j][k] != -1)
        return;
    if (k % 2 == 0) {
        for (const int &x : a) {
            if (x == j) continue;
            recurse(i - x, x, k + 1);
        }
    }
    else {
        for (const int &x : a) {
            if (x == j) continue;
            recurse(i + x, x, k + 1);
        }
    }
    choice[i + 10][j][k] = 1;
}

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    cin >> n;

    for (int i = 0; i < 10; i++) if (s[i] == '1') a.push_back(i + 1);

    if (a.empty()) {
        cout << "NO\n";
        return 0;
    }

    memset(choice, -1, sizeof(choice));
    recurse(0, 0, 1);

    if (!flag) {
        cout << "NO\n";
        return 0;
    }

    int i = ans.first, j = ans.second, k = n + 1;
    vi vec;

    cout << "YES\n";
    while (k > 1) {
        if (k % 2 == 0) i -= j;
        else i += j;

        vec.push_back(j);
        k -= 1;

        for (int idx = 1; idx <= 10; idx++) {
            if (choice[i + 10][idx][k] != -1 and idx != j) {
                j = idx;
                break;
            }
        }
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i] << " ";
    }

    return 0;
}