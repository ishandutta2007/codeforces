#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> stat(n, "");
    int x = 0;

    for (int i = 0; i < n; i++) {
        cin >> stat[i];
        if (stat[i][0] == '+' or stat[i][1] == '+' or stat[i][2] == '+')
            x += 1;
        if (stat[i][0] == '-' or stat[i][1] == '-' or stat[i][2] == '-')
            x -= 1;
    }

    cout << x;
}