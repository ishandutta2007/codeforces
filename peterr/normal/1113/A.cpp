#include <iostream>

using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;

    int cost = 0, fuel = 0, totalFuel = 0;
    for (int i = 1; i <= n; i++)
    {
        while (totalFuel < n - 1 && fuel < v)
        {
            cost += i;
            fuel++;
            totalFuel++;
        }
        fuel--;
    }

    cout << cost << endl;

    return 0;
}