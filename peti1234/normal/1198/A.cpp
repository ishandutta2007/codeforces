#include <bits/stdc++.h>

using namespace std;
int n, k,x, y, maxi, db=1;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k*=8;
    k/=n;
    k=min(k, 30);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    while(y<n) {
        if (db<=(1<<k)) {
            y++;
            if (y!=n && v[y]!=v[y-1]) {
                db++;
            }
            maxi=max(maxi, y-x);
        } else {
            x++;
            if (v[x]!=v[x-1]) {
                db--;
            }
        }
    }
    cout << n-maxi << endl;
    return 0;
}