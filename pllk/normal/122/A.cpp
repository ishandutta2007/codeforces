#include <iostream>

using namespace std;

int n;

bool l(int n) {
    if (n == 0) return false;
    if (n == 4) return true;
    if (n == 7) return true;
    int a = n%10;
    if (a == 4 || a == 7) return l(n/10);
    else return false;
}

int main() {
    cin >> n;
    int v = 0;
    for (int i = 1; i <= n; i++) {
        if (n%i == 0 && l(i)) v = 1;
    }
    if (v == 0) cout << "NO\n";
    else cout << "YES\n";
}