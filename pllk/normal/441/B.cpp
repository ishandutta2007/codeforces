#include <iostream>

using namespace std;

int n, v;
int x[3030];
int c;

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[a] += b;
    }
    for (int i = 1; i <= 3001; i++) {
        int z = v;
        if (x[i-1] > z) {x[i-1] -= z; c += z; z = 0;}
        else {c += x[i-1]; z -= x[i-1]; x[i-1] = 0;}
        if (x[i] > z) {x[i] -= z; c += z; z = 0;}
        else {c += x[i]; z -= x[i]; x[i] = 0;}
    }
    cout << c << "\n";
}