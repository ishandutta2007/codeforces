//
//  main.cpp
//  487A.cpp
//
//  Created by Sazanovich Nikita on 12/4/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int h1, a1, d1, h2, a2, d2, hc, ac, dc, ans = 2e9;
    cin >> h1 >> a1 >> d1 >> h2 >> a2 >> d2 >> hc >> ac >> dc;
    for (int acnt = 0; acnt <= 200; acnt++) for (int dcnt = 0; dcnt <= 100; dcnt++) {
        int sum = acnt * ac + dcnt * dc;
        int damage = a1 + acnt - d2;
        if (damage <= 0) continue;
        int turns = (h2 + damage - 1) / damage;
        int health = h1 - turns * (a2 - d1 - dcnt);
        if (health < 1) sum += (1 - health) * hc;
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}