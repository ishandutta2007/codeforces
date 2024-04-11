#include <iostream>
using namespace std;

int main() {
    int Y, B, R;
    cin >> Y >> B >> R;
    cout << 3 * min(min(Y + 1, B), R - 1) << '\n';
}