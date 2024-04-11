#include <bits/stdc++.h>

using namespace std;
const int c=602, sok=1000005000;
int n, m, alap[c][2*c], sum[c][c];
bool kesz[c][c];
vector<int> vel;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            alap[i][j]=sok;
            sum[i][j]=sok;
        }
    }
    for (int i=0; i<n; i++) {
        vel.push_back(i);
        sum[i][i]=0;
    }
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        alap[a][b]=c;
    }
    for (int i=0; i<n; i++) {
        for (int j=1; j<3*n; j++) {
            int x1=(j-1)%n, x2=j%n;
            alap[i][x2]=min(alap[i][x2], alap[i][x1]+1);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=n; j<2*n; j++) {
            alap[i][j]=alap[i][j-n];
        }
    }
    for (int kezd=0; kezd<n; kezd++) {
        for (int i=0; i<n; i++) {
            int mini=-1;
            for (int j=0; j<n; j++) {
                if (!kesz[kezd][j] && (mini==-1 || sum[kezd][j]<sum[kezd][mini])) {
                    mini=j;
                }
            }
            kesz[kezd][mini]=1;
            for (int j=0; j<n; j++) {
                sum[kezd][j]=min(sum[kezd][j], sum[kezd][mini]+alap[mini][j-sum[kezd][mini]%n+n]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}