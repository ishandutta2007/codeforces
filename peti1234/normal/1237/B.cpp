#include <bits/stdc++.h>

using namespace std;
int n, be[100001], ki[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> be[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        ki[x]=i;
    }
    int maxi=0, db=0;
    for (int i=1; i<=n; i++) {
        if (ki[be[i]]<maxi) {
            db++;
        }
        maxi=max(maxi, ki[be[i]]);
    }
    cout << db << "\n";
    return 0;
}