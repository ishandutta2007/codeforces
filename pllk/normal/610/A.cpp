#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll c = 0;

int main() {
    cin >> n;
    if (n%2 == 1) {
        cout << "0\n";
        return 0;
    }
    c = (n-2)/2;
    if (n%4 == 0) c--;
    c /= 2;
    cout << c << "\n";
}