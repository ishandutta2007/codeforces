#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        string answer;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                answer += 'a' + (10 * (s[i - 2] - '0') + (s[i - 1] - '0') - 1);
                i -= 2;
            } else {
                answer += 'a' + (s[i] - '1');
            }
        }

        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }
    return 0;
}