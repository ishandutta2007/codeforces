#include <bits/stdc++.h>

using namespace std;
const int c=3005;
long long n, m, a, b, t[c][c], t2[c][c], t3[c][c], ert, x, y, z, ans;
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> ert >> x >> y >> z;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            t[i][j]=ert;
            ert=(ert*x+y)%z;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            while (q.size()>0 && t[i][j]<=t[i][q.front()]) {
                q.pop_front();
            }
            q.push_front(j);
            if (q.back()==j-b) {
                q.pop_back();
            }
            if (j>=b) {
                t2[i][j-b+1]=t[i][q.back()];
            }
        }
        q.clear();
    }
    /*cout << "t2\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << t2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
             while (q.size()>0 && t2[i][j]<=t2[q.front()][j]) {
                q.pop_front();
            }
            q.push_front(i);
            if (q.back()==i-a) {
                q.pop_back();
            }
            if (i>=a) {
                t3[i-a+1][j]=t2[q.back()][j];
            }
        }
        q.clear();
    }
    /*cout << "t3\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << t3[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans+=t3[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}