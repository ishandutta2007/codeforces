//
//  main.cpp
//  499A
//
//  Created by Sazanovich Nikita on 12/25/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, x;
    cin >> n >> x;
    int cur = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        while (cur + x <= l) cur += x;
        while (cur <= r) ans++, cur++;
    }
    cout << ans << "\n";
    return 0;
}