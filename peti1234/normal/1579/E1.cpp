#include <bits/stdc++.h>

using namespace std;
int w, n, mini;
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        mini=n+1;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x<mini) {
                q.push_front(x);
                mini=x;
            } else {
                q.push_back(x);
            }
        }
        for (auto x:q) {
            cout << x << " ";
        }
        cout << "\n";
        q.clear();
    }
    return 0;
}