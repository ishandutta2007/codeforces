#include <bits/stdc++.h>

using namespace std;
long long w, n, k, sum;
vector<long long> a[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (x>0) a[0].push_back(x);
            else a[1].push_back(-x);
        }
        for (int i=0; i<2; i++) {
            a[i].push_back(0);
            sort(a[i].begin(), a[i].end());
            int si=a[i].size();
            for (int j=si-1; j>=0; j-=k) {
                sum+=a[i][j];
            }
        }
        cout << 2*sum-max(a[0].back(), a[1].back()) << "\n";
        sum=0;
        a[0].clear(), a[1].clear();
    }

    return 0;
}