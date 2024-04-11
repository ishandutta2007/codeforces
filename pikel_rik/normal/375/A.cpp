#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

string s;
int n;

int modulo(const string &a) {
    int m = 0;
    for (int c : a)
        m = (m * 10 + c - 'a') % 7;
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    vector<int> num(4, -1);
    int ptr = 0, ptr1 = n - 1;

    string s1 = s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            s1[ptr1--] = '0';
            continue;
        }
        if (s[i] == '1' and num[0] == -1)
            num[0] = 1;
        else if (s[i] == '6' and num[1] == -1)
            num[1] = 6;
        else if (s[i] == '8' and num[2] == -1)
            num[2] = 8;
        else if (s[i] == '9' and num[3] == -1)
            num[3] = 9;
        else s1[ptr++] = s[i];
    }

    do {
        s1[ptr] = (char)(num[0] + '0');
        s1[ptr + 1] = (char)(num[1] + '0');
        s1[ptr + 2] = (char)(num[2] + '0');
        s1[ptr + 3] = (char)(num[3] + '0');
        if (modulo(s1) == 0)
            break;
    } while (next_permutation(all(num)));

    cout << s1 << "\n";
    return 0;
}