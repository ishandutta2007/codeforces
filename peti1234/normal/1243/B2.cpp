#include <bits/stdc++.h>

using namespace std;
const int c=26;
int w, n, db[c];
string a, b;
vector<pair<int, int> > ans;
void add(int x, int y) {
    ans.push_back({x+1, y+1});
    swap(a[x], b[y]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        for (int i=0; i<c; i++) {
            db[i]=0;
        }
        ans.clear();
        for (auto x:a) {
            db[x-'a']++;
        }
        for (auto x:b) {
            db[x-'a']++;
        }
        bool baj=0;
        for (int i=0; i<c; i++) {
            if (db[i]%2) {
                baj=1;
            }
        }
        if (baj) {
            cout << "No\n";
            continue;
        }
        for (int i=0; i<n; i++) {
            if (b[i]==a[i]) {
                continue;
            }
            for (int j=i+1; j<n; j++) {
                if (b[j]==a[i]) {
                    add(j, j);
                }
                if (a[j]==a[i]) {
                    add(j, i);
                    break;
                }
            }
        }
        cout << "Yes\n";
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}