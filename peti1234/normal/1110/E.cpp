#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
int d[100001];
vector<int> v;
vector<int> q;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (i>1) {
            v.push_back(t[i]-t[i-1]);
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> d[i];
        if (i>1) {
            q.push_back(d[i]-d[i-1]);
        }
    }
    if (t[1]!=d[1] || t[n]!=d[n]) {
        cout << "no";
        return 0;
    }
    sort(v.begin(), v.end());
    sort(q.begin(), q.end());
    for (int i=0; i<v.size(); i++) {
        if (v[i]!=q[i]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}