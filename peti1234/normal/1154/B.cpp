#include <bits/stdc++.h>

using namespace std;
int n, a=101, b;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        a=min(a, x);
        b=max(b, x);
        s.insert(x);
    }
    int si=s.size();
    if (si==1) {
        cout << 0 << "\n";
    }
    if (si==2) {
        cout << ((b-a)%2 ? b-a : (b-a)/2) << "\n";
    }
    if (si==3) {
        int c=0;
        for (auto p:s) {
            if (p!=a && p!=b) {
                c=p;
            }
        }
        cout << (b-c==c-a  ? b-c : -1) << "\n";
    }
    if (si>3) {
        cout << -1 << "\n";
    }
    return 0;
}