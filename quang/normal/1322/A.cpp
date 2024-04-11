#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> (s + 1);
    int res = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        int flag = cur < 0;
        if (s[i] == '(') cur++;
        else cur--;
        flag |= (cur < 0);
        if (flag) res++;
    }
    if (cur != 0) cout << -1 << endl;
    else 
    cout << res << endl;
    return 0;
}