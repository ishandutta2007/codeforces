//
//  main.cpp
//  496C
//
//  Created by Sazanovich Nikita on 12/22/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
const int N = 200;

string s[N];
bool ok[N];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int j = 0; j < m; j++) {
        bool need = false;
        for (int i = 1; i < n; i++) {
            if (ok[i]) continue;
            if (s[i - 1][j] > s[i][j]) need = true;
        }
        if (need) {
            ans++;
            continue;
        }
        for (int i = 1; i < n; i++) if (s[i - 1][j] < s[i][j]) ok[i] = true;
    }
    cout << ans << "\n";
    return 0;
}