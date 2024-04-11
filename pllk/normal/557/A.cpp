#include <iostream>

using namespace std;

int n;
int a1, b1;
int a2, b2;
int a3, b3;

int main() {
    cin >> n;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    int u1 = a1;
    int u2 = a2;
    int u3 = a3;
    int s = u1+u2+u3;
    while (s < n) {
        if (u1 < b1) {u1++; s++;}
        else if (u2 < b2) {u2++; s++;}
        else {u3++; s++;}
    }
    cout << u1 << " " << u2 << " " << u3 << "\n";
}