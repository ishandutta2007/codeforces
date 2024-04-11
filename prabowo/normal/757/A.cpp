#include <bits/stdc++.h>
using namespace std;

int main() {
    map <char, int> cnt;
    string s;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (cnt.find(s[i]) != cnt.end())
            cnt[s[i]]++;
        else cnt[s[i]] = 1;
    }

    int arr[7] = {cnt['B'], cnt['u'] / 2, cnt['l'], cnt['b'], cnt['a'] / 2, cnt['s'], cnt['r']};

    int ans = arr[0];
    for (int i=1; i<7; i++)
        ans = min(ans, arr[i]);

    cout << ans << endl;
    return 0;
}