#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int t[c], sol[c], pr, n;
priority_queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, n*=2;
    for (int i=1; i<=n; i++) {
        char c; cin >> c;
        if (c=='-') {
            int x; cin >> x;
            t[i]=-x;
        }
    }
    for (int i=n; i>=1; i--) {
        if (t[i]) {
            q.push(t[i]);
        }
        else {
            if (q.size()>0) {
                t[i]=-q.top();
                q.pop();
            } else {
                pr=1;
                break;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (t[i]>0) {
            q.push(-t[i]);
        } else {
            if (q.size()>0) {
                if (t[i]!=q.top()) {
                    pr=1;
                }
                q.pop();
            } else {
                pr=-1;
                break;
            }
        }
    }
    if (pr) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            if (t[i]>0) cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}