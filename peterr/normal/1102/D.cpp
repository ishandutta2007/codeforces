#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char* s = new char[n];
    int target = n / 3;
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i] == '0')
            a++;
        else if (s[i] == '1')
            b++;
        else
            c++;
    }

    if (a > target && b > target)
    {
        int index = n - 1;
        while (a > target && b > target)
        {
            if (s[index] == '0' || s[index] == '1')
            {
                if (s[index] == '0')
                    a--;
                else
                    b--;

                s[index] = '2';
                c++;
            }

            index--;
        }
    }
    if (a > target && c > target)
    {
        int index = 0;
        while (a > target && c > target)
        {
            if (s[index] == '2')
            {
                s[index] = '1';
                b++;
                c--;
            }

            index++;
        }
    }
    if (b > target && c > target)
    {
        int index = 0;
        while (b > target && c > target)
        {
            if (s[index] == '1' || s[index] == '2')
            {
                if (s[index] == '1')
                    b--;
                else
                    c--;

                s[index] = '0';
                a++;
            }

            index++;
        }
    }
    if (a > target)
    {
        int index = n-1;
        while (a > target)
        {
            if (s[index] == '0')
            {
                if (c < target)
                {
                    s[index] = '2';
                    c++;
                }
                else
                {
                    s[index] = '1';
                    b++;
                }

                a--;
            }

            index--;
        }
    }
    if (b > target)
    {
        int index = 0;
        while (a < target)
        {
            if (s[index] == '1')
            {
                s[index] = '0';
                a++;
            }
            b--;
            index++;
        }
        index = n-1;
        while (c < target)
        {
            if (s[index] == '1')
            {
                s[index] = '2';
                c++;
            }
            b--;
            index--;
        }
    }
    if (c > target)
    {
        int index = 0;
        while (c > target)
        {
            if (s[index] == '2')
            {
                if (a < target)
                {
                    s[index] = '0';
                    a++;
                }
                else
                {
                    s[index] = '1';
                    b++;
                }
                c--;
            }
            index++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << s[i];

    return 0;
}