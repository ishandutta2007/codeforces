//
//  main.cpp
//  496B
//
//  Created by Sazanovich Nikita on 12/26/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string best = "";
    for (int i = 0; i < n; i++)
        best += "9";
    for (int i = 0; i < n; i++) {
        string b = "";
        int mod = ('0' + 10 - s[i]) % 10;
        for (int j = i; j < n; j++) b += (s[j] + mod <= '9') ? s[j] + mod : s[j] + mod - 10;
        for (int j = 0; j < i; j++) b += (s[j] + mod <= '9') ? s[j] + mod : s[j] + mod - 10;
        if (best > b) best = b;
    }
    cout << best << "\n";
    return 0;
}