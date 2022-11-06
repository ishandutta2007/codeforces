#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 1)
            ones++;
        else
            twos++;
    }
    if (ones == 0)
    {
        for (int i = 0; i < twos; i++)
            cout << 2 << " ";
    }
    else if (twos == 0)
    {
        for (int i = 0; i < ones; i++)
            cout << 1 << " ";
    }
    else
    {
        cout << 2 << " " << 1 << " ";
        for (int i = 1; i < twos; i++)
            cout << 2 << " ";
        for (int i = 1; i < ones; i++)
            cout << 1 << " ";
    }

    return 0;
}