#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> (s + 1);
    long long res = 0;
    set<int> ss;
    long long curSum = 0;
    int last = n;
    for (int i = n; i; i--) {
        if (s[i] == '0') {
            last = i - 1;
        } else {
            auto it = ss.upper_bound(last);
            if (it == ss.end()) {
                curSum += n + 1 - i;
                ss.insert(i);
            } else {
                curSum -= (n + 1 - *it);
                ss.erase(it);
                curSum += n + 1 - i;
                ss.insert(i);
            }
        }
        res += curSum;
    }
    cout << res << endl;
    return 0;   
}