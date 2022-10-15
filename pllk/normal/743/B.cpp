#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll k;
int c;

int main() {
    cin >> n >> k;
    c = 1;
    while (k%2 == 0) {
        c++;
        k /= 2;
    }
    cout << c << "\n";
}