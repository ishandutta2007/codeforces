#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sol = 1;
    int count = 1;
    while (n-- > 1)
    {
        sol += count * 4;
        count++;
    }
    cout << sol;
    return 0;
}