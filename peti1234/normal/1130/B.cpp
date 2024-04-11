#include <bits/stdc++.h>

using namespace std;
int n;
int x=1, y=1;
long long sum;
vector<int> sz[100001];
int main()
{
    cin >> n;
    for (int i=1; i<=2*n; i++) {
        int x;
        cin >> x;
        sz[x].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
    }
    for (int i=1; i<=n; i++) {
        sum+=abs(sz[i][0]-x)+abs(sz[i][1]-y);
        x=sz[i][0];
        y=sz[i][1];
    }
    cout << sum << endl;
    return 0;
}