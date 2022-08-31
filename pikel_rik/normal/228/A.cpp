#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(4, 0);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    int c = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (a[i] == a[j])
                c += 1;
        }
    }

    if (c == 6)
        cout << "3";
    else if (c == 3)
        cout << "2";
    else
        cout << c;

    return 0;
}