#include <bits/stdc++.h>

using namespace std;
int w, n, maxi;
vector<int> a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        maxi=0;
        for (int i=1; i<n; i*=2) {
            a.clear(), b.clear();
            for (int j=1; j<=n; j++) {
                if (j&i) {
                    a.push_back(j);
                } else {
                    b.push_back(j);
                }
            }
            cout << a.size() << " " << b.size() << " ";
            for (int i:a) cout << i << " ";
            for (int i:b) cout << i << " ";
            cout.flush() << "\n";
            int x; cin >> x;
            maxi=max(maxi, x);
        }
        cout << -1 << " " << maxi;
        cout.flush() << "\n";
    }
    return 0;
}