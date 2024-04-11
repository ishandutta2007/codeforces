#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
int sz[100001][2];
set<int> k;
bool gyoker(int k)
{
    for (int i=1; i<n; i++) {
        if (t[sz[i][1]]!=t[sz[i][2]]) {
            if (k!=sz[i][1] && k!=sz[i][2]) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        sz[i][1]=x;
        sz[i][2]=y;
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        k.insert(i);
    }
    for (int i=1; i<n; i++) {
        if (t[sz[i][1]]!=t[sz[i][2]]) {
            if (gyoker(sz[i][1]) || gyoker(sz[i][2])) {
                cout << "YES" << endl;
                if (gyoker(sz[i][1])) {
                    cout << sz[i][1] << endl;
                }
                else {
                    cout << sz[i][2] << endl;
                }
                return 0;
            }
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl << 1 << endl;
    return 0;
}