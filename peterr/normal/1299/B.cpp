#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<int, int> pts[MAXN + 1];
pair<int, int> edges[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].first >> pts[i].second;
    }
    pts[n] = pts[0];
    for (int i = 0; i < n; i++)
    {
        edges[i] = make_pair(pts[i + 1].first - pts[i].first, pts[i + 1].second - pts[i].second);
    }
    if (n % 2 == 0)
    {
        bool valid = true;
        for (int i = 0; i < n / 2; i++)
        {
            if (make_pair(-edges[i].first, -edges[i].second) != edges[i + n / 2])
                valid = false;
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}