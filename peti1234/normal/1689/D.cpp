#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, m, kk, kn, nk, nn, ans, xx, yy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        kk=kn=nk=nn=-1e7;
        ans=1e7, xx=0, yy=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                if (c=='B') {
                    kk=max(kk, -i-j);
                    kn=max(kn, -i+j);
                    nk=max(nk, i-j);
                    nn=max(nn, i+j);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int s=0;
                s=max(s, i+j+kk);
                s=max(s, i-j+kn);
                s=max(s, -i+j+nk);
                s=max(s, -i-j+nn);

                if (s<ans) {
                    ans=s;
                    xx=i, yy=j;
                }
            }
        }
        //cout << "valasz......... ";
        cout << xx << " " << yy << "\n";
    }
    return 0;
}
/*
1
7
1 2
1 5
2 3
2 4
5 6
5 7
*/