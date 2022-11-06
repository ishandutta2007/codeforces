#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;

    int r = 5;
    while (k / r >= 5 && k % r != 0)
    {
        r++;
    }

    string vowels = "aeiou";

    if (k % r == 0 && k / r >= 5)
    {
        int c = k / r;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << vowels[(i + j) % 5];
            }
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}