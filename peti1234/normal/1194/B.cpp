#include <bits/stdc++.h>
 
using namespace std;
vector<int> t[50001];
int a[50001];
int b[50001];
int c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> c;
    for (int i=1; i<=c; i++) {
        int n, m;
        cin >> n >> m;
        int maxa=0, maxb=0;
        for (int i=0; i<n; i++) {
            a[i]=0;
        }
        for (int i=0; i<m; i++) {
            b[i]=0;
        }
        for (int i=0; i<n; i++) {
            t[i].clear();
        }
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<m; j++) {
                if (s[j]=='.') {
                    t[i].push_back(0);
                } else {
                    t[i].push_back(1);
                    a[i]++;
                    b[j]++;
                    maxa=max(maxa, a[i]);
                    maxb=max(maxb, b[j]);
                }
            }
        }
        bool v=false;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i]==maxa && b[j]==maxb && t[i][j]==0) {
                    v=true;
                }
            }
        }
        cout << n+m-maxa-maxb-v << "\n";
    }
    return 0;
}