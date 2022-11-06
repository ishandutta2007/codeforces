#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
bool used[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(used + 1, used + n + 1, false);
        int person = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            bool flag = false;
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                if (!used[x] && !flag)
                {
                    used[x] = true;
                    flag = true;
                }
            }
            if (!flag)
                person = i + 1;
        }
        if (person)
        {
            cout << "IMPROVE" << "\n";
            int king = 1;
            while (used[king])
                king++;
            cout << person << " " << king << "\n";
        }
        else
            cout << "OPTIMAL" << "\n";
    }
    return 0;
}