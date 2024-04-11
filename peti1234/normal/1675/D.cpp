#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, p[c], db[c];
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            db[p[i]]++;
        }
        int cnt=0;
        for (int i=1; i<=n; i++) {
            if (!db[i]) {
                cnt++;
            }
        }
        if (n==1) {
            db[1]=0, cnt=1;
        }
        cout << cnt << "\n";
        for (int i=1; i<=n; i++) {
            if (db[i]) continue;

            vector<int> sz;
            int x=i;
            while (!v[x]) {
                v[x]=1;
                sz.push_back(x);
                x=p[x];
            }
            cout << sz.size() << "\n";
            reverse(sz.begin(), sz.end());
            for (auto x:sz) {
                cout << x << " ";
            }
            cout << "\n";
        }

        for (int i=1; i<=n; i++) {
            p[i]=0, db[i]=0, v[i]=0;
        }
    }
    return 0;
}
// n=1 !
/*
1
5
3 1 3 3 1
*/