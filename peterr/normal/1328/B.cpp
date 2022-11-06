#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ind = n - 2;
        k--;
        int ind2 = n - 1;
        while (k)
        {
            int num = n - 1 - ind;
            if (k >= num)
            {
                k -= num;
                ind--;
            }
            else
            {
                while (k)
                {
                    k--;
                    ind2--;
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (i == ind || i == ind2)
                cout << "b";
            else
                cout << "a";
        cout << endl;
    }
    return 0;
}