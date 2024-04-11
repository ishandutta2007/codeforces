#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string x;
        cin >> x;

        string a = "1", b = "1";

        int flag = -1;

        for (int i = 1; i < n; i++) {
            if (x[i] == '2') {
                a.push_back('1');
                b.push_back('1');
            }
            else if (x[i] == '1') {
                a.push_back('1');
                b.push_back('0');
                flag = i;
                break;
            }
            else {
                a.push_back('0');
                b.push_back('0');
            }
        }

        if (flag != -1) {
            for (int i = flag + 1; i < n; i++) {
                a.push_back('0');
                b.push_back(x[i]);
            }
        }

        cout << a << "\n" << b << "\n";
    }
    return 0;
}