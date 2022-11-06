#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int ans2 = min(b2, a1) + min(b3, a2) + min(b1, a3);
    int ans1 = n;
    swap(a2, a3);
    swap(b2, b3);
    for (int i = 0; i < 3; i++)
    {
        if (a1 <= b1)
        {
            int temp = 0;
            temp += max(0, b1 - a1 - a3);
            int newa3 = max(0, a3 - (b1 - a1));
            temp += max(0, b3 - newa3 - a2);
            int newa2 = max(0, a2 - max(0, b3 - newa3));
            temp += max(0, b2 - newa2);
            ans1 = min(ans1, temp);
        }
        swap(a1, a2);
        swap(a1, a3);
        swap(b1, b2);
        swap(b1, b3);
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}