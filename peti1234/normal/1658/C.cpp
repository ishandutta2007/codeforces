#include <bits/stdc++.h>

using namespace std;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, pos=-1, baj=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
            if (x==1) {
                if (pos==-1) pos=i;
                else baj=1;
            }
        }
        if (pos==-1) {
            baj=1;
        } else {
            int el=1;
            for (int i=1; i<n; i++) {
                int x=sz[(pos+i)%n];
                if (x>el+1) baj=1;
                el=x;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
        sz.clear();
    }
    return 0;
}