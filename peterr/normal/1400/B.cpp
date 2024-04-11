#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int p, f, c1, c2, s, w;
        cin >> p >> f >> c1 >> c2 >> s >> w;
        if (s > w)
        {
            swap(s, w);
            swap(c1, c2);
        }
        int ans = 0;
        for (int i = 0; i <= c1; i++)
        {
            if (i * s > p)
                break;
            int temp = i;
            int leftover = p - i * s;
            int axes = leftover / w;
            int swords = c1 - i;
            if (f / s < swords)
            {
                temp += f / s;
            }
            else
            {
                temp += swords;
                leftover = f - swords * s;
                axes += leftover / w;
            }
            axes = min(axes, c2);
            temp += axes;
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
    return 0;
}