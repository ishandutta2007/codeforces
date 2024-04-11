#include <iostream>

using namespace std;

#define ll long long

ll n;

int main() {
    cin >> n;
    if (n == 3) {
        cout << "1\n";
        return 0;
    }
    if (n == 4) {
        cout << "4\n";
        return 0;
    }
    cout << 3*(n-3)+(n-3)*(n-4)+1 << "\n";
}