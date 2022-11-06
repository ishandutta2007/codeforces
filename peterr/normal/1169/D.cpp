#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i + 2;
        bool done = false;
        while (!done && j < s.length())
        {
            for (int k = 1; j - 2 * k >= i; k++)
            {
                if (s[j] == s[j - k] && s[j - k] == s[j - 2 * k])
                {
                    done = true;
                    break;
                }
            }

            if (!done)
                j++;
        }

        if (j < s.length())
            res += s.length() - j;
    }
    cout << res;

    return 0;
}