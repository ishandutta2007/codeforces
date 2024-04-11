#include <bits/stdc++.h>

using namespace std;
int n, m, a=0, b=0;
int p;
int t[300001][9];
vector<int> mask[513];
bool jo(int z)
{
    for (int i=0; i<p; i++) mask[i].clear();
    for (int i=1; i<=n; i++) {
        int sum=0;
        for (int j=0; j<m; j++) {
            if (t[i][j]>=z) sum+=(1<<j);
        }
        mask[sum].push_back(i);
    }
    for (int i=0; i<p; i++) {
        for (int j=0; j<p; j++) {
            if (mask[i].size() && mask[j].size() && (i|j)==p-1) {
                a=mask[i][0], b=mask[j][0];
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    p=(1<<m);
    for (int i=1; i<=n; i++) for (int j=0; j<m; j++) cin >> t[i][j];
    int x=-1, y=1000000001;
    while(y-x>1) {
        int z=(x+y)/2;
        if (jo(z)) x=z;
        else y=z;
    }
    cout << a << " " << b << "\n";
    return 0;
}