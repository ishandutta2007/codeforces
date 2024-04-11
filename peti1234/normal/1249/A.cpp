#include <bits/stdc++.h>

using namespace std;
int w, n, p;
vector<int> sz;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, sz.clear(), p=0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<n; i++) {
            if (sz[i]==sz[i-1]+1) p=1;
        }
        cout << 1+p << "\n";
    }
    return 0;
}