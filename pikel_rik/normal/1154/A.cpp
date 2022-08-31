#include <bits/stdc++.h>
using namespace std;

int main() {
    int x[4], max = 0;
    for (int i = 0; i < 4; i++) {
        cin >> x[i];
        if (x[i] > max)
            max = x[i];
    }

    for (int i = 0; i < 4; i++) {
        if (max - x[i] > 0)
            cout << max - x[i] << " ";
    }
    return 0;
}