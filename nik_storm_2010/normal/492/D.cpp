//
//  main.cpp
//  492D.cpp
//
//  Created by Sazanovich Nikita on 12/4/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        int a, l, r;
        cin >> a;
        a %= (x + y);
        l = -1, r = x;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (m + floor(1.0 * y * m / x) >= a) r = m; else l = m;
        }
        if (r + floor(1.0 * y * r / x) == a) {
            double z = floor(1.0 * y * r / x);
            if (1.0 * r / x == z / y) cout << "Both\n"; else cout << "Vanya\n";
            continue;
        }
        l = -1, r = y;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (m + floor(1.0 * x * m / y) >= a) r = m; else l = m;
        }
        double z = floor(1.0 * x * r / y);
        if (1.0 * r / y == z / x) cout << "Both\n"; else cout << "Vova\n";
    }
    return 0;
}