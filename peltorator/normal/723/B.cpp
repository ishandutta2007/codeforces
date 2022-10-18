#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> n >> s;
    int ans1 = 0, ans2 = 0;
    bool in = false;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            ans1 = max(ans1, len);
            len = 0;
            in = true;
        }
        else if (s[i] == ')')
        {
            if (len != 0)
                    ans2++;
            len = 0;
            in = false;
        }
        else if (s[i] == '_')
        {
            if (!in)
                ans1 = max(ans1, len);
            if (in && len != 0)
                ans2++;
            len = 0;
        }
        else
            len++;
    }
    ans1 = max(ans1, len);
    cout << ans1 << " " << ans2;
    return 0;
}