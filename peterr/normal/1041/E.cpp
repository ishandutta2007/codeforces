#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int freq[MAXN + 1];
int ans[MAXN];

bool solve(int n)
{
    ans[0] = n;
    int index = 0;
    int freePtr = n - 1;
    while (freePtr >= 1 && freq[freePtr] != 0)
        freePtr--;
    int cur = n - 1;
    if (freePtr > cur)
        return false;
    while (cur >= 1)
    {
        if (freq[cur] == 0)
            return false;
        ans[index + freq[cur]] = cur;
        for (int i = index + 1; i < index + freq[cur]; i++)
        {
            ans[i] = freePtr;
            freePtr--;
            while (freePtr >= 1 && freq[freePtr] != 0)
                freePtr--;
        }
        index = index + freq[cur];
        cur--;
        while (cur >= 1 && freq[cur] == 0)
            cur--;
        if (freePtr > cur)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool valid = true;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        freq[min(a, b)]++;
        if (max(a, b) != n || min(a, b) == n)
            valid = false;
    }
    if (!valid)
    {
        cout << "NO" << endl;
    }
    else
    {
        if (solve(n))
        {
            /*
            cout << "test" << endl;
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
            */
            cout << "YES" << endl;
            for (int i = 1; i < n; i++)
            {
                cout << ans[i - 1] << " " << ans[i] << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}