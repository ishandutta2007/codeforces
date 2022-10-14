#include <bits/stdc++.h>
using namespace std;
using lint = long double;

int grid[15][15];
int name[15][15];
int ladder[105];
lint expected[105];

int main() {

    for (int i = 1, k = 1; i <= 10; i++) {
        if (i & 1) {
            for (int j = 1; j <= 10; j++) {
                name[i][j] = k++;
            }
        }
        else {
            for (int j = 10; j >= 1; j--) {
                name[i][j] = k++;
            }
        }
    }

    for (int i = 10; i >= 1; i--) for (int j = 1; j <= 10; j++) {
        cin >> grid[i][j];
        ladder[name[i][j]] = name[grid[i][j] + i][j];
    }
    
    for (int k = 0; k <= 100000; k++) {
        for (int i = 99; i >= 1; i--) {
            lint j = expected[i] * 6;
            if (i + 1 <= 100) j += min(expected[i + 1], expected[ladder[i + 1]]) - expected[i];
            if (i + 2 <= 100) j += min(expected[i + 2], expected[ladder[i + 2]]) - expected[i];
            if (i + 3 <= 100) j += min(expected[i + 3], expected[ladder[i + 3]]) - expected[i];
            if (i + 4 <= 100) j += min(expected[i + 4], expected[ladder[i + 4]]) - expected[i];
            if (i + 5 <= 100) j += min(expected[i + 5], expected[ladder[i + 5]]) - expected[i];
            if (i + 6 <= 100) j += min(expected[i + 6], expected[ladder[i + 6]]) - expected[i];
            j /= 6;
            expected[i] = j + 1;
        }
    }

    cout << fixed << setprecision(15) << expected[1] << "\n";
}