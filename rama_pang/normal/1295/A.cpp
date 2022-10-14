#include <bits/stdc++.h>
using namespace std;

// Useful Numbers: 1 (cost 2), 7 (cost 3)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string ans;
        while (N - 2 >= 0) {
            N -= 2;
            ans.push_back('1');
        }
        while (N > 0) {
            ans.pop_back();
            ans.push_back('7');
            N--;
        }
        sort(begin(ans), end(ans));
        reverse(begin(ans), end(ans));
        cout << ans << "\n";
    }

}