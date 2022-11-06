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
        int d, k;
        cin >> d >> k;
        long long thresh = (long long) d * d / k / k;
        int man1 = 0;
        for (int i = 1; ; i++)
        {
            if ((long long) i * i * 2 > thresh)
                break;
            man1 += 2;
        }
        int man2 = 1;
        for (int i = 1; ; i++)
        {
            if ((long long) i * i + (long long) (i + 1) * (i + 1) > thresh)
                break;
            man2 += 2;
        }
        if (man1 > man2)
        {
            cout << "Utkarsh\n";
        }
        else
            cout << "Ashish\n";
    }
    return 0;
}