#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, a[c], b[c];
vector<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
    if (m==1) {
        cout << n << "\n";
        return 0;
    }
    for (int i=2; i<=m; i++) {
        s.push_back(b[i]-b[i-1]);
    }
    s.push_back(2e9);
    for (int i=2; i<=n; i++) {
        s.push_back(a[i]-a[i-1]);
    }

    int si=s.size();
    int db=0;
    vector<int> pi(si, 0);
    for (int i=1; i<si; i++) {
        int h=pi[i-1];
        while (h>0 && s[i]!=s[h]) {
            h=pi[h-1];
        }
        if (s[i]==s[h]) {
            h++;
        }
        pi[i]=h;
        if (pi[i]==m-1) {
            db++;
        }
    }
    cout << db << "\n";
    return 0;
}