#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <string.h>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    for (int i = 0; i <= min(a, b); ++i) {
        if (c == a - i + b - i) {
            cout << i << " " << b - i << " " << a - i;
            return 0;
        }
    }
    cout << "Impossible";
    
    return 0;
}