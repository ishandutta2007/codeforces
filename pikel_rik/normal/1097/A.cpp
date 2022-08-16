#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    string a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];

    bool ans = false;
    for (int i = 0; i < 5; i++) {
        ans = (s[0] == a[i][0] or s[1] == a[i][1]);
        if (ans)
            break;
    }

    if (ans)
        cout << "YES";
    else cout << "NO";
    return 0;
}