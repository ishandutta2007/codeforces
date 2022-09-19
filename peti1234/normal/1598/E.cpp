#include <bits/stdc++.h>

using namespace std;
const int c=1005;
long long n, m, q, ans, cnt;
bool v[c][c];
void calc(int ert, int s) {
    //cout << "calc " << ert << "\n";
    if (ert==n-1 || ert==-m) {
        return;
    }
    int x=1, y=1, dir=(ert<0 ? 1 : 0);
    if (ert<0) {
        y-=ert+1;
    } else {
        x+=ert;
    }
    //cout << "kezd " << x << " " << y << " " << dir << "\n";

    long long cnt=0;
    while (x<=n && y<=m) {
        if (!v[x][y]) {
            cnt++;
        } else {
            ans+=s*cnt*(cnt-1)/2;
            cnt=0;
        }
        if (dir==1) y++;
        else x++;
        dir=1-dir;
    }
    ans+=s*cnt*(cnt-1)/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    cnt=n*m;
    for (int i=1-m; i<=n-1; i++) {
        calc(i, 1);
    }
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        int s=a-b;
        calc(s-1, -1), calc(s, -1);
        cnt+=(v[a][b] ? 1 : -1);
        v[a][b]=!v[a][b];
        calc(s-1, 1), calc(s, 1);
        cout << ans+cnt << "\n";
    }
    return 0;
}
/*
2 2 1
1 2
*/