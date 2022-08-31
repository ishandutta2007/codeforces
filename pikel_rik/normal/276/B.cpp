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

    int n;
    n = s.length();

    vi count(26);
    for (char i : s) {
        count[(int)(i - 'a')] += 1;
    }

    int c = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0)
            c += 1;
    }

    if (c > 0) c -= 1;

    cout << (c % 2 == 0 ? "First\n" : "Second\n");

    return 0;
}