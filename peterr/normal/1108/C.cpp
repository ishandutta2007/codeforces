#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    char c[3] = {'R', 'G', 'B'};
    int step = 1;
    int fewest = 3e5;
    int start = 0;

    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        int i2 = i;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != c[i2])
            {
                count++;
            }
            i2 = (i2 + 1) % 3;
        }

        if (count < fewest)
        {
            fewest = count;
            step = 1;
            start = i;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        int i2 = i;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != c[i2])
            {
                count++;
            }
            i2 = (i2 - 1 + 3) % 3;
        }

        if (count < fewest)
        {
            fewest = count;
            step = -1;
            start = i;
        }
    }

    cout << fewest << endl;
    for (int i = 0; i < n; i++)
    {
        cout << c[start];
        start = (start + step + 3) % 3;
    }

    return 0;
}