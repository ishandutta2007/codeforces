#ifdef LOCAL
#include "stdafx.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL


using namespace std;


mt19937 mt (736);


void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m;

    cin >> n >> m;

    if (m == 1)
    {
        cout << n * (long long)n << endl;

        return;
    }

    vector<long long> cnt (m);

    for (int i = 0; i < m; i++)
        cnt[(i * i) % m] += (n - i + m) / m;
    cnt[0]--;

    for (auto it : cnt)
        cerr << it << ' ';
    cerr << endl;

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {
        int j = (m - i) % m;

        ans += cnt[i] * cnt[j];
    }

    cout << ans << endl;
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