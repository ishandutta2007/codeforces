#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int count[k][26], c = 0;
        memset(count, 0, sizeof(count));

        for (int i = 0; i < (k+1)/2; i++) {
            for (int j = 0; j < n/k; j++) {
                count[i][s[j*k+i]-'a'] += 1;
                if (i != k - i - 1)
                    count[i][s[j*k+k-i-1]-'a'] += 1;
            }
            int sum = accumulate(count[i], count[i]+26, 0);
            int m = *max_element(count[i], count[i]+26);
            c += sum - m;
        }
        cout << c << "\n";
    }
    return 0;
}