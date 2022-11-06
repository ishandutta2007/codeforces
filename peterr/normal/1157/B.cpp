#include <iostream>

using namespace std;

int main()
{
    int n;
    string num;
    int f[10];
    cin >> n >> num;
    for (int i = 1; i <= 9; i++)
    {
        cin >> f[i];
    }

    bool done = false;
    for (int i = 0; i < n && !done; i++)
    {
        int digit = num[i] - '0';
        if (digit < f[digit])
        {
            num[i] = '0' + f[digit];
            int k = i + 1;
            while (k < n)
            {
                digit = num[k] - '0';
                if (digit <= f[digit])
                {
                    num[k] = '0' + f[digit];
                    k++;
                }
                else
                {
                    break;
                }
            }
            done = true;
        }
    }

    cout << num;

    return 0;
}