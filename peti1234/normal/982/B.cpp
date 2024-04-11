#include <bits/stdc++.h>

using namespace std;
int n;
priority_queue<pair<int, int> > a, b;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        a.push({-x, i});
    }
    cin >> s;
    for (int i=0; i<2*n; i++) {
        if (s[i]=='0') {
            int ert=-a.top().first, id=a.top().second;
            a.pop();
            cout << id << " ";
            b.push({ert, id});
        } else {
            int id=b.top().second;
            b.pop();
            cout << id << " ";
        }
    }
    cout << "\n";
    return 0;
}