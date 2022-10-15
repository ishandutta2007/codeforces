#include <iostream>

using namespace std;

bool prime(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        int a = 1+d;
        while (!prime(a)) a++;
        int b = a+d;
        while (!prime(b)) b++;
        cout << a*b << "\n";
    }
}