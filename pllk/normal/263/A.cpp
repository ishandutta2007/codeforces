#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int y, x, a;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a;
            if (a == 1) {y = i; x = j;}
        }
    }
    cout << abs(x-2)+abs(y-2) << endl;
}