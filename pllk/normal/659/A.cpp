#include <iostream>

using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    while (b < 0) {a--; if (a == 0) a = n; b++;}
    while (b > 0) {a++; if (a == n+1) a = 1; b--;}
    cout << a << "\n";
}