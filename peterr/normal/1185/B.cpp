#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int i1 = 0, i2 = 0;
        bool valid = true;
        while (i1 < s1.length() && i2 < s2.length())
        {
            char cur = s1[i1];
            int count = 0;
            while (i1 + 1 < s1.length() && s1[i1 + 1] == cur)
            {
                i1++;
                count++;
            }
            if (s2[i2] != cur)
            {
                valid = false;
                break;
            }
            else
            {
                while (i2 + 1 < s2.length() && s2[i2 + 1] == cur)
                {
                    i2++;
                    count--;
                }
                if (count > 0)
                {
                    valid = false;
                    break;
                }
            }
            i1++;
            i2++;
        }
        if (i1 < s1.length() || i2 < s2.length())
            valid = false;
        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}