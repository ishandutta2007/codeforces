#include <bits/stdc++.h>

using namespace std;
int n;
int p[501][501];
int sz[501][501];
int t[501];
int m[501][501];
vector<long long> j;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> p[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=n; j>=1; j--) {
            sz[n+1-i][j]=p[t[i]][t[n-j+1]];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            m[i][j]=sz[i][j];
        }
    }
    long long os=0;
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                m[i][j]=min(m[i][j], m[i][k]+m[k][j]);
            }
        }
        os=0;
        for (int i=1; i<=k; i++) {
            for (int j=1; j<=k; j++) {
                os+=m[i][j];
            }
        }
        j.push_back(os);
    }
    reverse(j.begin(), j.end());
    for (int i=0; i<j.size(); i++) {
        cout << j[i] << " ";
    }
    return 0;
}