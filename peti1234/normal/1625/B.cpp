#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, maxi=-1;
        cin >> n;
        map<int, int> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            int s=m[x];
            if (s>0) {
                maxi=max(maxi, s+n-i);
            }
            m[x]=i;
        }
        m.clear();
        //cout << "valasz........ ";
        cout << maxi << "\n";
    }
    return 0;
}