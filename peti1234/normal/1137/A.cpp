#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[1001][1001];
int sm[1001][1001];
int bi[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        vector<int> x;
        vector<int> y;
        for (int j=1; j<=m; j++) {
            x.push_back(t[i][j]);
        }
        sort(x.begin(), x.end());
        for (int i=0; i<x.size(); i++) {
            if (y.size()==0 || x[i]!=y.back()) {
                y.push_back(x[i]);
            }
        }
        for (int j=1; j<=m; j++) {
            int a=0, b=y.size();
            while(b-a>1) {
                int c=(a+b)/2;
                if (y[c]<=t[i][j]) {
                    a=c;
                } else {
                    b=c;
                }
            }
            int si=y.size();
            sm[i][j]=max(sm[i][j], a);
            bi[i][j]=max(bi[i][j],si-a);
        }
    }
    for (int j=1; j<=m; j++) {
        vector<int> x;
        vector<int> y;
        for (int i=1; i<=n; i++) {
            x.push_back(t[i][j]);
        }
        sort(x.begin(), x.end());
        for (int i=0; i<x.size(); i++) {
            if (y.size()==0 || x[i]!=y.back()) {
                y.push_back(x[i]);
            }
        }
        for (int i=1; i<=n; i++) {
            int a=0, b=y.size();
            while(b-a>1) {
                int c=(a+b)/2;
                if (y[c]<=t[i][j]) {
                    a=c;
                } else {
                    b=c;
                }
            }
            int si=y.size();
            sm[i][j]=max(sm[i][j], a);
            bi[i][j]=max(bi[i][j], si-a);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << sm[i][j]+bi[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}