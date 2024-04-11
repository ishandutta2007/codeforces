#include<iostream>

using namespace std;

int a[150];

int main () {
    string s;
    int n, cnt = 0;
    cin >> s >> n;
    for (int i = 0; i < s.size(); i++) {
        if (a[s[i]] == 0) cnt++;
        a[s[i]]++;
    }
    if (cnt <= n) {
        for (int i = 1; i <= s.size(); i++) {
            string ans = "";
            for (int j = 'a'; j <= 'z'; j++) {
                int k = (a[j] + i - 1) / i;
                for (int x = 1; x <= k; x++) ans += j;
            }
            if (ans.size() <= n) {
                while (ans.size() != n) ans += 'a';
                cout << i << endl << ans;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}