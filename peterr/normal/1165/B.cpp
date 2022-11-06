#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* contests = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> contests[i];
    }

    sort(contests, contests + n);
    int day = 1;
    int index = 0;
    while (index < n)
    {
        while (index < n && contests[index] < day)
        {
            index++;
        }
        if (index < n)
        {
            day++;
            index++;
        }
    }

    cout << (day - 1);

    return 0;
}