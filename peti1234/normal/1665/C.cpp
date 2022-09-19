#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, si, ans, db[c];
vector<int> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        for (int i=1; i<=n; i++) {
            if (db[i]) {
                a.push_back(db[i]);
            }
        }
        a.push_back(1);
        sort(a.begin(), a.end());
        si=a.size();
        for (int i=0; i<si; i++) {
            b.push_back(max(0, a[i]-i-1));
        }

        ans=si;

        sort(b.rbegin(), b.rend());
        while (b.size()>0 && b.back()==0) {
            b.pop_back();
        }
        while (b.size()>0) {
            for (int i=0; i<b.size(); i++) {
                b[i]--;
            }
            b[0]--;
            sort(b.rbegin(), b.rend());
            while (b.size()>0 && b.back()<=0) {
                b.pop_back();
            }
            ans++;
        }

        cout << ans << "\n";

        ans=0, si=0;
        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
        a.clear(), b.clear();
    }
    return 0;
}
/*
1
6
1 1 1 1 1
*/