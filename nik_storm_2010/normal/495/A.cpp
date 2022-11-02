//
//  main.cpp
//  495A
//
//  Created by Sazanovich Nikita on 12/20/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>

using namespace std;

int cnt[10];

int main(int argc, const char * argv[]) {
    cnt[0] = 2;
    cnt[1] = 7;
    cnt[2] = 2;
    cnt[3] = 3;
    cnt[4] = 3;
    cnt[5] = 4;
    cnt[6] = 2;
    cnt[7] = 5;
    cnt[8] = 1;
    cnt[9] = 2;
    int n;
    cin >> n;
    int c1 = n % 10, c2 = n / 10;
    cout << cnt[c1] * cnt[c2] << "\n";
    return 0;
}