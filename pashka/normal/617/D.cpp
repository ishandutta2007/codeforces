#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>


// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int x[3], y[3];
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    if ((x[0] == x[1] && x[0] == x[2]) || (y[0] == y[1] && y[0] == y[2])) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (y[i] == y[j] && x[i] < x[j]) {
                int xx = x[3 - i - j];
                if (xx <= x[i] || xx >= x[j]) {
                    cout << 2;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x[i] == x[j] && y[i] < y[j]) {
                int yy = y[3 - i - j];
                if (yy <= y[i] || yy >= y[j]) {
                    cout << 2;
                    return 0;
                }
            }
        }
    }

    cout << 3;

    return 0;
}