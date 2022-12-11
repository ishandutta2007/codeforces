#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int cnt[26];
        fill(cnt, cnt+26, 0);

        for (char ch : str) cnt[ch-'a']++;
        int type = 0;
        for (int i = 0; i < 26; ++i) type += cnt[i] > 0;

        if (type == 1) {
            cout << -1 << endl;
        } else {

            string ans = "";
            for (int i = 0; i < 26; ++i) {
                while (cnt[i] > 0) {
                    cnt[i]--;
                    ans += (char) (i + 'a');
                }
            }

            cout << ans << endl;
        }
    }
    
    return 0;
}