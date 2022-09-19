#include <bits/stdc++.h>

using namespace std;
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int w, n, m, kx, ky;
vector<vector<int> > ert;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        ert.resize(n+2);
        for (int i=0; i<n+2; i++) {
            ert[i].resize(m+2);
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                ert[i][j]=(c=='#' ? 0 : c=='L' ? 2 : 1);
                if (ert[i][j]==2) kx=i, ky=j;
            }
        }

        queue<pair<int, int> > q;
        q.push({kx, ky});
        while (q.size()>0) {
            int x=q.front().first, y=q.front().second;
            q.pop();
            for (int l=0; l<4; l++) {
                int xl=x+dx[l], yl=y+dy[l];
                if (1<=xl && xl<=n && 1<=yl && yl<=m && ert[xl][yl]==1) {
                    int jo=0, rossz=0;
                    for (int l2=0; l2<4; l2++) {
                        int s=ert[xl+dx[l2]][yl+dy[l2]];
                        if (s==2) rossz++;
                        if (s==1) jo++;
                    }
                    if (jo==0 || (jo==1 && rossz>0)) {
                        ert[xl][yl]=2;
                        q.push({xl, yl});
                    }
                }
            }
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int s=ert[i][j];
                if (s==0) cout << "#";
                if (s==1) cout << ".";
                if (s==2) {
                    //cout << "fontos " << i << " " << j << " " << kx << " " << ky << "\n";
                    if (i==kx && j==ky) cout << "L";
                    else cout << "+";
                }
            }
            cout << "\n";
        }

        ert.clear();
    }
    return 0;
}

/*
1
1 1
L
*/