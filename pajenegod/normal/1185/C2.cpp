#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> T(n);
    for (auto &t : T)
        cin >> t;

    vector<int> counter(101);
    for (int j = 0; j <n; ++j)
    {
        int t = T[j];

        int time = m - t;
        int used = 0;
        for (int i = 1; i <= 100; ++i)
        {
            int pick = min(time / i, counter[i]);
            used += pick;
            time -= pick * i;
        }

        counter[t] += 1;
        cout << j - used << ' ';
    }

}