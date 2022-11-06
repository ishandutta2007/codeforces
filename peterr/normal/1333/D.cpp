#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
bool isLeft[MAXN];

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int lo = 0;
    int hi = 0;
    int prev = -4;
    int numLeft = 0;
    for (int i = 0; i < n; i++)
    {
        isLeft[i] = s[i] == 'L';
        if (isLeft[i])
        {
            hi += i - numLeft;
            lo = max(prev + 1, i - numLeft);
            prev = lo;
            numLeft++;
        }
    }
    if (k >= lo && k <= hi)
    {
        int extra = hi - k;
        queue<int> q;
        for (int i = 1; i < n; i++)
            if (isLeft[i] && !isLeft[i - 1])
                q.push(i);
        while(!q.empty())
        {
            int num = 1 + min(extra, (int) q.size() - 1);
            extra -= num - 1;
            cout << num;
            for (int i = 0; i < num; i++)
            {
                int x = q.front();
                cout << " " << x;
                q.pop();
                isLeft[x] = false;
                isLeft[x - 1] = true;
                if (x + 1 < n && isLeft[x + 1])
                    q.push(x + 1);
                if (x - 2 >= 0 && !isLeft[x - 2])
                    q.push(x - 1);
            }
            cout << "\n";
        }
    }
    else
        cout << -1 << endl;
    return 0;
}