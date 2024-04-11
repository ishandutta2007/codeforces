#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10, inf = 2e9 + 1;

#define inf long long;

int n;

int q[maxn], kitten[maxn];

main(){
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i] > '0')
            ans += s[i] - '0';
        else
            if (i > 1)
                ans += (s[i - 1] - 48) * 10 - s[i - 1] + 48;
    cout << ans + 1;
}