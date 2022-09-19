#include <bits/stdc++.h>

using namespace std;
const int c=55;
int n, k, t[4][c];
vector<pair<int, pair<int, int> > > ans;
void lep(int a, int b, int c, int d) {
    ans.push_back({t[a][b], {c, d}});
    t[c][d]=t[a][b], t[a][b]=0;
}
int main()
{
    cin >> n >> k;
    for (int i=0; i<4; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
        }
    }
    for (int kor=0; kor<5*n; kor++) {
        for (int a=1; a<=2; a++) {
            for (int s=1; s<=n; s++) {
                int b=(a==1 ? s : n+1-s);
                if (!t[a][b]) continue;
                int aa=(a==1 ? 0 : 3);
                if (t[a][b]==t[aa][b]) {
                    lep(a, b, aa, b);
                    continue;
                }
                int sa=a, sb=b;
                if (a==1) {
                    if (b==1) sa=2;
                    else sb=b-1;
                } else {
                    if (b==n) sa=1;
                    else sb=b+1;
                }
                if (!t[sa][sb]) {
                    lep(a, b, sa, sb);
                }
            }
        }
    }
    for (int i=1; i<=2; i++) {
        for (int j=1; j<=n; j++) {
            if (t[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second.first+1 << " " << x.second.second << "\n";
    }

    return 0;
}
/*
10 20
18 7 3 16 5 8 19 2 20 12
15 16 7 11 14 3 12 4 8 10
19 18 20 1 17 9 5 2 6 13
11 15 13 17 6 9 14 1 10 4
*/