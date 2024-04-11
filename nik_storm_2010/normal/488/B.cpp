//
//  main.cpp
//  488B
//
//  Created by Sazanovich Nikita on 12/4/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>

using namespace std;
const int N = 2e3;

int used[N], bad;

void modify(int x, int delta) {
    if (used[x] == 0 && delta == +1) bad++;
    if (used[x] == 1 && delta == -1) bad--;
    used[x] += delta;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        modify(x, +1);
    }
    for (int x1 = 1; x1 <= 500; x1++) {
        int x4 = 3 * x1;
        modify(x1, -1);
        modify(x4, -1);
        for (int x2 = x1, x3 = x4; x2 <= x3; x2++, x3--) {
            modify(x2, -1);
            modify(x3, -1);
            if (bad > 0) {
                modify(x2, +1);
                modify(x3, +1);
                continue;
            }
            cout << "YES\n";
            for (int i = 1; i < N; i++) for (int j = 1; j <= -used[i]; j++) cout << i << "\n";
            return 0;
        }
        modify(x1, +1);
        modify(x4, +1);
    }
    cout << "NO\n";
    return 0;
}