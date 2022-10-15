#include <iostream>

using namespace std;

typedef long long ll;
ll n;

int main() {
    cin >> n;
    for (int i = 1; ; i++) {
        if (n > i) {
            n -= i;
        } else {
            cout << n << "\n";
            return 0;
        }
    }
}