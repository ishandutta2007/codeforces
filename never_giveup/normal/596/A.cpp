#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<long long, long long> q[n];
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        if (q[i].first != q[j].first && q[i].second != q[j].second){
            cout << (max(q[i].first, q[j].first) - min(q[i].first, q[j].first)) * (max(q[i].second, q[j].second) - min(q[i].second, q[j].second));
            return 0;
        }
    cout << -1;
}