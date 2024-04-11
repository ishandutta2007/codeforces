#include <bits/stdc++.h>

using namespace std;
const int c=505, c2=c*c;
int n, k, t[c][c], kis[c2], nagy[c2], bal[c2], jobb[c2], cnt, db[c2], pref[c][c];
void check() {
    int dif=cnt-k;
    for (int l=1; l<=n; l++) {
        for (int i=1; i<=n*n; i++) {
            if (!db[i]) continue;
            //if (i!=2) continue;
            //cout << "... " << i << "\n";
            //cout << nagy[i] << " " << kis[i] << " " << jobb[i] << " " << bal[i] << "\n";
            if (nagy[i]-kis[i]>=l || jobb[i]-bal[i]>=l) continue;
            int aa=max(1, nagy[i]-l+1), bb=min(kis[i], n-l+1), cc=max(1, jobb[i]-l+1), dd=min(bal[i], n-l+1);
            bb++, dd++;
            pref[aa][cc]++, pref[aa][dd]--, pref[bb][cc]--, pref[bb][dd]++;
            //if (l==3) cout << "add " << i << " " << aa << " " << bb << " " << cc << " " << dd << "\n";
        }
        if (l==3) {
            //cout << "... " << pref[1][1] << "\n";
        }
        for (int i=1; i<=n-l+1; i++) {
            for (int j=1; j<=n-l+1; j++) {
                pref[i][j]+=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
                //cout << "fontos " << l << " " << i << " " << j << " " << pref[i][j] << "\n";
                if (pref[i][j]==dif || pref[i][j]==dif+1) {
                    cout << 1 << "\n";
                    exit(0);
                }
            }
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                pref[i][j]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            t[i][j]=x;
            if (!db[x]) cnt++;
            db[x]++;
            if (!kis[x] || i<kis[x]) kis[x]=i;
            if (!nagy[x] || i>nagy[x]) nagy[x]=i;
            if (!bal[x] || j<bal[x]) bal[x]=j;
            if (!jobb[x] || j>jobb[x]) jobb[x]=j;
        }
    }
    if (cnt==k) {
        cout << 0 << "\n";
        return 0;
    }
    check();

    if (cnt>k) {
        cout << 2 << "\n";
    } else {
        cout << k-cnt << "\n";
    }


    return 0;
}
/*
3 1
1 2 3
4 5 6
7 8 9
*/