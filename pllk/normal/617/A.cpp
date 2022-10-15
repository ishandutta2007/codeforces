#include <iostream>

using namespace std;

int x;
int d[1111111];

int main() {
    cin >> x;
    d[0] = 0;
    for (int i = 1; i <= x; i++) {
        d[i] = 999999999;
        for (int j = 1; j <= 5; j++) {
            if (i-j >= 0) d[i] = min(d[i],d[i-j]+1);
        }
    }
    cout << d[x] << "\n";
}