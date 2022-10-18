#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

char a[6] = { 'A', 'E', 'I', 'O', 'U', 'Y' };

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    int last = -1;
    for (int i = 0; i < s.size(); i++)
    {
        bool ok = false;
        for (int j = 0; j < 6; j++)
            if (a[j] == s[i])
                ok = true;
        if (ok)
        {
            ans = max(ans, i - last);
            last = i;
        }
    }
    int q = s.size();
    ans = max(ans, q - last);
    cout << ans;
    return 0;
}