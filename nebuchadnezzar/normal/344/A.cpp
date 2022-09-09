#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <string.h>

using namespace std;

int n;
string s;

int main() {
    cin >> n;
    int ans = 0;
    string mem = "";
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (i == 0 || mem != s) {
            ans += 1;
        }
        mem = s;
    }

    cout << ans;
    
    return 0;
}