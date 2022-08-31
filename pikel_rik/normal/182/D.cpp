#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() > s2.length())
        swap(s1, s2);

    int n = s1.length(), m = s2.length();

    int g = __gcd(n, m);

    vector<int> div;
    for (int i = 1; i * (ll)i <= g; i++) {
        if (g % i == 0) {
            div.push_back(i);
            if (i != g / i)
                div.push_back(g / i);
        }
    }

    sort(all(div));
    string temp;
    int ptr = 0;
    bool flag = true;

    for (int i : div) {
        while (temp.length() != i)
            temp += s1[ptr++];
        flag = true;

        for (int j = 0; j < n; j++) {
            if (s1[j] != s1[j % temp.length()]) {
                flag = false;
                break;
            }
        }

        if (flag) break;
    }

    if (!flag) {
        cout << "0\n";
        return 0;
    }

    flag = true;
    for (int i = 0; i < m; i++) {
        if (s2[i] != temp[i % temp.length()]) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout << "0\n";
        return 0;
    }

    int c = 0;
    for (int i = 1;; i++) {
        int num = temp.length() * i;
        if (n % num == 0 and m % num == 0)
            c += 1;
        if (num > n or num > m)
            break;
    }

    cout << c << "\n";
    return 0;
}