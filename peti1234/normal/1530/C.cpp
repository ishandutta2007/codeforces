#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.rbegin(), a.rend()), sort(b.rbegin(), b.rend());
        for (int i=1; i<n; i++) {
            a[i]+=a[i-1], b[i]+=b[i-1];
        }
        for (int i=0; ; i++) {
            int db=n+i, db2=db-db/4;
            int sa=i*100+a[min(n-1, db2-i-1)], sb=b[min(n-1, db2-1)];
            if (sa>=sb) {
                cout << i << "\n";
                break;
            }
        }
        a.clear(), b.clear();
    }
    return 0;
}