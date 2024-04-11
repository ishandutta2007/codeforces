#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair

using namespace std;

int n, n0, n5, num;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num == 0) {
            ++n0;
        } else {
            ++n5;
        } 
    }

    if (n0 == 0) {
        cout << "-1";
        return 0;
    }

    if (n5 / 9 == 0) {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < n5 / 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << "5";
        }
    }

    for (int i = 0; i < n0; ++i) {
        cout << "0";    
    }

    return 0;
}