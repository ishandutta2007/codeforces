#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int deg[MAXN + 1];
vector<tuple<int, int, int>> cand;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> deg[i];
        for (int j = 1; j < i; j++)
        {
            int a = i;
            int b = j;
            if (deg[a] > deg[b])
                swap(a, b);
            cand.push_back({deg[b] - deg[a], a, b});
        }
    }
    sort(cand.begin(), cand.end());

    while (!cand.empty())
    {
        tuple<int, int, int> tup = cand.back();
        cand.pop_back();
        int v = get<1>(tup);
        int u = get<2>(tup);
        cout << "? " << u << " " << v << endl;
        string q;
        cin >> q;
        if (q == "Yes")
        {
            cout << "! " << u << " " << v << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}