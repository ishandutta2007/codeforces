#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
int ans[MAXN];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = cur; j < n; j++)
        {
            int key = s[j] - 'a';
            if (key == i)
            {
                ans[j] = 1;
                cur = j + 1;
            }
        }
    }
    string test = "";
    for (int i = 0; i < n; i++)
        if (ans[i] == 0)
            test += s[i];
    bool valid = true;
    for (int i = 1; i < (int) test.length(); i++)
        if (test[i] < test[i - 1])
            valid = false;
    if (valid)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}