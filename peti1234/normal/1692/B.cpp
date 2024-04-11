#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        set<int> s;
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int si=s.size();
        while (n>si) {
            n-=2;
        }
        cout << n << "\n";
    }
    return 0;
}