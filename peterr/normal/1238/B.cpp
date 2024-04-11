#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int monsters[MAXN];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, r;
        cin >> n >> r;
        for (int i = 0; i < n; i++)
        {
            cin >> monsters[i];
        }
        sort(monsters, monsters + n);
        int origin = 0;
        int index = n - 1;
        int ans = 0;
        while (index >= 0 && origin < monsters[index])
        {
            ans++;
            int pos = monsters[index];
            while (index >= 0 && monsters[index] == pos)
                index--;
            origin += r;
        }
        cout << ans << endl;
    }
    return 0;
}