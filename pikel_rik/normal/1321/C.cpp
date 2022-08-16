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

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (char i = 'z'; i >= 'a'; i--) {
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == i and ((j > 0 and s[j - 1] == i - 1) or (j + 1 < s.length() and s[j + 1] == i - 1))) {
                s.erase(s.begin() + j);
                j -= 1;
            }
        }
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] == i and ((j > 0 and s[j - 1] == i - 1) or (j + 1 < s.length() and s[j + 1] == i - 1))) {
                s.erase(s.begin() + j);
                j += 1;
            }
        }
    }

    cout << n - s.length();
    return 0;
}