#include <bits/stdc++.h>

using namespace std;

int a[100000];

int q[100000];

map<int, vector<int> > e;

map<int, int> k;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i], a[i] = q[i];
    sort(q, q + n);
    for (int i = 0; i < n; i++)
        e[q[i]].push_back(i);
    int l = 0, ans = 0, mx = -1;
    for (int i = 0; i < n; i++){
        mx = max(mx, e[a[i]][k[a[i]]]);
        k[a[i]]++;
        if (i == mx)
            ans++, l = i + 1, mx = -1;
    }
    cout << ans;
}