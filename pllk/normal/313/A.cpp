#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    if (n >= -9) {
        cout << n << endl;
        return 0;
    }
    n = -n;
    int a = n/10;
    int b = (n/100)*10+n%10;
    a = -a;
    b = -b;
    if (a > b) cout << a << endl;
    else cout << b << endl;
}