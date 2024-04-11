#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1024;
bool used[MAXN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
        cout << "! " << 1 << endl;
    int block = k == 1 ? 1 : k / 2;
    int numB = n / block;
    char c;
    for (int i = 0; i < numB; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int start = j * block + 1;
            for (int z = 0; z < block; z++)
            {
                cout << "? " << start + z << endl;
                cin >> c;
                if (c == 'Y')
                    used[start + z] = true;
            }
            start = i * block + 1;
            for (int z = 0; z < block; z++)
            {
                cout << "? " << start + z << endl;
                cin >> c;
                if (c == 'Y')
                    used[start + z] = true;
            }
            cout << "R" << endl;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!used[i])
            ans++;
    cout << "! " << ans << endl;
    return 0;
}