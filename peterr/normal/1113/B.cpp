#include <iostream>

using namespace std;

int powerReduce(int a, int b)
{
    int red = 0;
    for (int div = 2; div <= b; div++)
    {
        if (b % div == 0)
        {
            red = max(red, (a + b) - (a * div + b / div));
        }
    }
    return red;
}

int main()
{
    int n;
    cin >> n;

    int* power = new int[n];
    int totalPower = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
        totalPower += power[i];
    }

    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (power[i] < power[minIndex])
            minIndex = i;
    }

    int red = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == minIndex)
            continue;

        red = max(red, powerReduce(power[minIndex], power[i]));
    }

    cout << (totalPower - red) << endl;
    return 0;
}