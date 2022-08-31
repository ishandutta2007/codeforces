#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

int n, ans[N];
string a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i].erase(a[i].begin());
        ans[i] = a[i].length();
    }

    for (int i = n - 1; i >= 1; i--) {
        int temp = -1;
        for (int j = 0; j < min(ans[i], ans[i-1]); j++) {
            if (a[i-1][j] < a[i][j]) {
                temp = a[i-1].length();
                break;
            }
            if (a[i-1][j] > a[i][j]) {
                temp = j;
                break;
            }
        }
        if (temp == -1 and a[i-1].length() > ans[i])
            ans[i-1] = ans[i];
        else if (temp == -1)
            ans[i-1] = a[i-1].length();
        else ans[i-1] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << "#";
        for (int j = 0; j < ans[i]; j++) cout << a[i][j];
        cout << "\n";
    }
    return 0;
}