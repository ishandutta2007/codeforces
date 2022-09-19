#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n;
bool kesz[c];
vector<int> p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x<=n && !kesz[x]) {
                kesz[x]=1;
            } else {
                p.push_back(x);
            }
        }
        sort(p.begin(), p.end());
        bool baj=0;
        int pos=1;
        for (auto x:p) {
            while (kesz[pos]) {
                pos++;
            }
            if (2*pos>=x) {
                baj=1;
            }
            kesz[pos]=1;
        }

        if (baj) {
            cout << -1 << "\n";
        } else {
            cout << p.size() << "\n";
        }

        p.clear();
        for (int i=1; i<=n; i++) {
            kesz[i]=0;
        }
    }
    return 0;
}