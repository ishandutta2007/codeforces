#include <iostream>
using namespace std;

const int DIGITS = 300;

int main() {
    for (int i = 0; i < DIGITS; i++)
        cout << 5;

    cout << '\n';

    for (int i = 0; i < DIGITS; i++)
        cout << (i < DIGITS - 1 ? 4 : 5);

    cout << '\n';
    return 0;
}