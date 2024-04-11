#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    int* dur = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dur[i];
    }

    if (x <= y)
    {
        int count = 0;
        while (*min_element(dur, dur + n) <= x)
        {
            count++;
            int index = -1;
            for (int i = 0; i < n; i++)
            {
                if (dur[i] <= x && (index == -1 ||dur[i] > dur[index]))
                {
                    index = i;
                }
            }

            dur[index] = 1000000;

            index = -1;
            for (int i = 0; i < n; i++)
            {
                if (dur[i] <= x && (index == -1 ||dur[i] > dur[index]))
                {
                    index = i;
                }
            }

            dur[index] += y;
        }

        cout << count;
    }
    else
    {
        cout << n;
    }

    return 0;
}