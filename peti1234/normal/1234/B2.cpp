#include <bits/stdc++.h>

using namespace std;
set<int> s;
int n, k, si;
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (s.find(x)==s.end()) {
            if (si==k) {
                s.erase(q.back());
                q.pop_back();
                si--;
            }
            q.push_front(x);
            s.insert(x);
            si++;
        }
    }
    cout << q.size() << "\n";
    for (auto x:q) {
        cout << x << " ";
    }
    return 0;
}