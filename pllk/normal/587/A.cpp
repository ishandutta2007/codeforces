#include <iostream>
#include <algorithm>

using namespace std;

int n;
int c[1010101];
int z;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    for (int i = 0; i <= 1000100; i++) {
        while (c[i] >= 2) {
            c[i+1]++;
            c[i] -= 2;
        }
        if (c[i] == 1) z++;
    }
    cout << z << "\n";
}