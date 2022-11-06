#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        s += 'X';
        int cnt = 0;
        vector<int> stacks;
        for (int i = 0; i < (int) s.length(); i++)
        {
            if (s[i] == 'X')
            {
                if (cnt >= b)
                    stacks.push_back(cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        if (2 * b <= a)
        {
            if ((int) stacks.size() == 1 && stacks[0] >= a && stacks[0] <= a + 2 * b - 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if ((int) stacks.size() == 0)
                cout << "NO" << endl;
            else
            {
                bool lose = false;
                int extra = 0;
                int y = 0;
                for (int x : stacks)
                {
                    if (x < a)
                        lose = true;
                    if (x >= 2 * b)
                    {
                        extra++;
                        y = x;
                    }
                }
                if (lose || extra > 1)
                    cout << "NO" << endl;
                else if (extra == 0)
                {
                    cout << ((int) stacks.size() % 2 == 0 ? "NO" : "YES") << endl;
                }
                else
                {
                    bool even = (y >= a && y <= a + 2 * b - 2) || (y >= 3 * a && y <= a + 4 * b - 2);
                    bool odd = y >= 2 * a && y <= a + 3 * b - 2;
                    if ((int) stacks.size() % 2 == 0 && odd)
                        cout << "YES" << endl;
                    else if ((int) stacks.size() % 2 != 0 && even)
                        cout << "YES" << endl;
                    else
                        cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}