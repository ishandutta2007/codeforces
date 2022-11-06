#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int rem = x % 4;
    if (rem == 1)
    {
        cout << 0 << " " << "A";
    }
    else if (rem == 2)
    {
        cout << 1 << " " << "B";
    }
    else if (rem == 3)
    {
        cout << 2 << " " << "A";
    }
    else
    {
        cout << 1 << " " << "A";
    }
    return 0;
}