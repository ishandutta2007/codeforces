#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    while (true) {
        if (n%10 == 1) n /= 10;
        else if (n%100 == 14) n /= 100;
        else if (n%1000 == 144) n /= 1000;
        else break;
    }
    if (n == 0) cout << "YES\n";
    else cout << "NO\n";
}