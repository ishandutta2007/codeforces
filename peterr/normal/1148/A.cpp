#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == b)
    {
        cout << (a + b + 2 * c);
    }
    else
    {
        if (a < b)
            swap(a, b);
        cout << (b + b + 1 + 2 * c);
    }
    return 0;
}