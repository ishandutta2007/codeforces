//
//  main.cpp
//  494A
//
//  Created by Sazanovich Nikita on 12/22/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>

using namespace std;
const int N = 2e5;

int ans[N];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int)s.length();
    int balance = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') balance++;
        if (s[i] == ')') balance--;
        if (s[i] == '#') {
            ans[cnt++] = 1;
            balance--;
        }
        if (balance < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    ans[cnt - 1] += balance;
    balance = cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') balance++;
        if (s[i] == ')') balance--;
        if (s[i] == '#') balance -= ans[cnt++];
        if (balance < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < cnt; i++) cout << ans[i] << "\n";
    return 0;
}