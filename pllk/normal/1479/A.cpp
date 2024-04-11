#include <iostream>

using namespace std;

int n;

int ask(int k) {
    cout << "? " << k << endl;
    int x;
    cin >> x;
    return x;
}

int dir(int k) {
    int a = k == 1 ? 1e9 : ask(k-1);
    int b = ask(k);
    int c = k == n ? 1e9 : ask(k+1);
    if (a < b && b < c) return 1;
    if (a > b && b > c) return 2;
    if (a < b && b > c) return 3;
    if (a > b && b < c) return 4;
}

void lol(int a, int b) {
    int c = (a+b)/2;
    int d = dir(c);
    if (d == 1 || d == 3) {
        lol(a,c-1);
    }
    if (d == 2) {
        lol(c+1,b);
    }
    if (d == 4) {
        cout << "! " << c << endl;
    }
}

int main() {
    cin >> n;
    lol(1,n);
}