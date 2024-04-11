#include <iostream>

using namespace std;

bool isInteresting(int x)
{
    int count = 0;
    while (x > 0)
    {
        count += x % 10;
        x /= 10;
    }
    return (count % 4 == 0);
}

int main()
{
    int a;
    cin >> a;
    while (!isInteresting(a))
        a++;
    cout << a;
    return 0;
}