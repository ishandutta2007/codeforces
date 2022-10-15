#include <iostream>

using namespace std;

bool qq[5050][5050];

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        s = "*"+s;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                qq[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) qq[i][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; i-j >= 1 && i+j <= n; j++) {
                if (s[i-j] != s[i+j]) break;
                qq[i-j][i+j] = 1;
            }
            for (int j = 1; i-j+1 >= 1 && i+j <= n; j++) {
                if (s[i-j+1] != s[i+j]) break;
                qq[i-j+1][i+j] = 1;
            }
        }
        int pp = 0, pi = 0, pw = 0, pd = 0;
        for (int i = 0; i <= n; i++) {
            if (2*i > n) break;
            if (i != 0 && s[i] != s[n-i+1]) break;
            int w1 = 0, w2 = 0;
            for (int j = i+1; j <= n-i; j++) {
                if (qq[i+1][j]) w1 = max(w1,j-(i+1)+1);
                if (qq[j][n-i]) w2 = max(w2,n-i-j+1);
            }
            if (2*i+w1 > pp) {
                pp = 2*i+w1;
                pi = i;
                pw = w1;
                pd = 1;
            }
            if (2*i+w2 > pp) {
                pp = 2*i+w2;
                pi = i;
                pw = w2;
                pd = 2;
            }
        }
        for (int i = 1; i <= pi; i++) cout << s[i];
        if (pd == 1) {
            for (int k = 0; k < pw; k++) {
                cout << s[pi+1+k];
            }
        } else {
            for (int k = 0; k < pw; k++) {
                cout << s[n-pi-pw+k+1];
            }
        }
        for (int i = n-pi+1; i <= n; i++) cout << s[i];
        cout << "\n";
    }
}