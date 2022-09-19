#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, c, dp[1601][3], per, xo;
long long t[300002];
bool v[6];
int mex(int x, int y, int z) {
    v[0]=0, v[1]=0, v[2]=0, v[3]=0;
    v[x]=1, v[y]=1, v[z]=1;
    for (int i=0; i<4; i++) if (!v[i]) return i;
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> a >> b >> c, xo=0;
        for (int i=1; i<=1600; i++) for (int j=0; j<3; j++) {
            int x=0, y=0, z=0;
            if (i>=a) x=dp[i-a][0];
            if (j!=1 && i>=b) y=dp[i-b][1];
            if (j==1) y=5;
            if (j!=2 && i>=c) z=dp[i-c][2];
            if (j==2) z=5;
            dp[i][j]=mex(x, y, z);
            /*if (!j) cout << endl;
            cout << dp[i][j] << " ";*/
        }
        for (int p=1; p<=1500; p++) {
            bool jo=true;
            for (int i=0; i<5; i++) for (int j=0; j<3; j++) if (dp[i+50][j]!=dp[i+50+p][j]) jo=0;
            if (jo) per=p, p=1600;
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]>1000) t[i]-=50, t[i]%=per, t[i]+=50;
            xo=(xo^dp[t[i]][0]);
        }
        int db=0;
        for (int i=1; i<=n; i++) {
            int p=dp[t[i]][0];
            if (t[i]>=a && (p^dp[t[i]-a][0])==xo) db++;
            if (t[i]<a && p==xo) db++;
            if (t[i]>=b && (p^dp[t[i]-b][1])==xo) db++;
            if (t[i]<b && p==xo) db++;
            if (t[i]>=c && (p^dp[t[i]-c][2])==xo) db++;
            if (t[i]<c && p==xo) db++;
        }
        cout << db << "\n";
    }
    return 0;
}
/*
1
2 1 3 4
6 7
*/