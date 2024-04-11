#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        bool poss1 = true;
        bool poss2 = true;
        int prev;
        cin >> prev;
        for (int i = 0; i < n - 1; i++)
        {
            int cur;
            cin >> cur;
            if ((cur - prev + n) % n != 1)
                poss1 = false;
            if ((prev - cur + n) % n != 1)
                poss2 = false;
            prev = cur;
        }
        if (poss1 || poss2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}