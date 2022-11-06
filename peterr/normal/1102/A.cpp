#include <iostream>

using namespace std;

int main()
{
    long long i;
    cin >> i;

    if (i % 4 == 0 || i % 4 == 3)
        cout << 0;
    else if (i % 4 == 1 || i % 4 == 2)
        cout << 1;

    return 0;
}