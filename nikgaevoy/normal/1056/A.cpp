#ifdef LOCAL
#include "stdafx.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL


using namespace std;


mt19937 mt (736);


void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<bool> good (101, true);

    for (int i = 0; i < n; i++)
    {
        int r;

        cin >> r;

        vector<bool> bus (101, false);

        for (int j = 0; j < r; j++)
        {
            int t;

            cin >> t;

            bus[t] = true;
        }

        for (int j = 0; j < bus.size (); j++)
            good[j] = good[j] & bus[j];
    }

    for (int i = 0; i < good.size (); i++)
        if (good[i])
            cout << i << ' ';
    cout << endl;
}


int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    ifstream fin ("input.txt");

    solve (fin);

    cout << setprecision (4) << "clock: " << clock () / (double)CLOCKS_PER_SEC << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}