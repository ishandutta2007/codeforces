#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int ans[MAXN];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int ind = 0;
    while (cnt < n)
    {
        ind++;
        int cur = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = cur; j < n; j++)
            {
                int key = s[j] - 'a';
                if (key == i && ans[j] == 0)
                {
                    ans[j] = ind;
                    cur = j + 1;
                    cnt++;
                }
            }
        }
    }
    cout << ind << endl;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}