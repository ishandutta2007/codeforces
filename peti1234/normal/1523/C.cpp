#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x!=1) {
                while (sz.back()+1!=x) {
                    sz.pop_back();
                }
                sz.pop_back();
            }
            sz.push_back(x);
            int si=sz.size();
            for (int i=0; i<si; i++) {
                cout << sz[i];
                if (i!=si-1) {
                    cout << '.';
                }
            }
            cout << "\n";
        }
        sz.clear();
    }
    return 0;
}