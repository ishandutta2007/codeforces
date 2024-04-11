#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int cc[200] = {0};
        for (int i = 0; i < n; i++) {
            int c = s[i]-'0';
            for (int u = 0; u <= 9; u++) {
                cc[100+u*10+c] = cc[100+10*c+u]+1;
            }
        }
        int p = 0;
        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                int x = cc[100+a*10+b];
                if (a != b && x%2 == 1) x--;
                p = max(p,x);
            }
        }
        cout << n-p << "\n";
    }
}