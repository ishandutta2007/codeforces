#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n;
long double t[c][c], u[c], prob[c], eps=1e-6;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            t[i][j]=x;
            t[i][j]/=100;
        }
    }
    for (int i=1; i<n; i++) {
        u[i]=1;
    }
    for (int i=1; i<=n; i++) {
        int mini=0;
        long double pr_mini=1e9;
        for (int j=1; j<=n; j++) {
            if (!v[j] && u[j]<1-eps) {
                long double s=(prob[j]+u[j])/(1-u[j]);
                if (s<pr_mini) {
                    pr_mini=s;
                    mini=j;
                }
            }
        }
        v[mini]=1;
        prob[mini]=pr_mini;
        for (int j=1; j<=n; j++) {
            if (!v[j]) {
                prob[j]+=u[j]*t[j][mini]*(1+prob[mini]);
                u[j]*=1-t[j][mini];
            }
        }
    }
    cout.precision(20);
    cout << prob[1] << "\n";
    return 0;
}