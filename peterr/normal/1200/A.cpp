#include <bits/stdc++.h>

using namespace std;

bool occ[10];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            for (int j = 0; j < n; j++)
            {
                if (!occ[j])
                {
                    occ[j] = true;
                    break;
                }
            }
        }
        else if (s[i] == 'R')
        {
            for (int j = 9; j >= 0; j--)
            {
                if (!occ[j])
                {
                    occ[j] = true;
                    break;
                }
            }
        }
        else
        {
            int index = s[i] - '0';
            occ[index] = false;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << occ[i];
    cout << endl;
    return 0;
}