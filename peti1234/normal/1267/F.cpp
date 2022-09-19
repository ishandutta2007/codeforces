#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, nn, mm, db[c];
vector<int> kis, nagy;
priority_queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> nn >> mm;
    if (nn>=m || mm>=n) {
        cout << "No\n";
        return 0;
    }
    for (int i=1; i<=nn; i++) {
        int x;
        cin >> x;
        db[x]++;
        kis.push_back(x);
    }
    while (nn<m-1) {
        kis.push_back(1);
        db[1]++;
        nn++;
    }
    for (int i=1; i<=mm; i++) {
        int x;
        cin >> x;
        db[x]++;
        nagy.push_back(x);
    }
    while (mm<n) {
        nagy.push_back(n+m);
        db[n+m]++;
        mm++;
    }
    reverse(kis.begin(), kis.end()), reverse(nagy.begin(), nagy.end());
    for (int i=1; i<=n+m; i++) {
        if (!db[i]) {
            q.push(-i);
        }
    }
    cout << "Yes\n";
    for (int i=1; i<n+m; i++) {
        int a=-q.top(), b;
        q.pop();
        if (a>n) {
            b=kis.back();
            kis.pop_back();
        } else {
            b=nagy.back();
            nagy.pop_back();
        }
        db[b]--;
        if (!db[b]) {
            q.push(-b);
        }
        cout << a << " " << b << "\n";

    }
    return 0;
}