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
    else
    {
        int block = k == 1 ? 1 : k / 2;
        int numB = n / block;
        for (int jump = 1; jump < numB; jump++)
        {
            for (int startB = 0; startB < min(jump, numB - jump); startB++)
            {
                for (int b = startB; b < numB; b += jump)
                {
                    int startInd = b * block + 1;
                    for (int z = 0; z < block; z++)
                    {
                        cout << "? " << startInd + z << endl;
                        char c;
                        cin >> c;
                        if (c == 'Y')
                            used[startInd + z] = true;
                    }
                }
                cout << "R" << endl;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (!used[i])
                ans++;
        cout << "! " << ans << endl;
    }
    return 0;
}