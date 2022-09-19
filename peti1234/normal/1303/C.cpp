#include <bits/stdc++.h>

using namespace std;
const int c=26;
bool t[c][c], v[c];
int w, n, db, cnt[c];
string s, ans;
bool baj;
void dfs(int a) {
    char p='a'+a;
    ans+=p;
    v[a]=1;
    for (int i=0; i<c; i++) {
        if (t[a][i] && !v[i]) {
            dfs(i);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size(), db=0;
        baj=0;
        ans.clear();
        for (int i=0; i<c; i++) {
            for (int j=0; j<c; j++) {
                t[i][j]=0;
            }
            cnt[i]=0, v[i]=0;
        }
        for (int i=1; i<n; i++) {
            int x=s[i]-'a', y=s[i-1]-'a';
            if (!t[x][y]) {
                db++;
                t[x][y]=1, t[y][x]=1;
                cnt[x]++, cnt[y]++;
            }
        }
        for (int i=0; i<c; i++) {
            if (cnt[i]==1) {
                dfs(i);
                break;
            }
        }
        if (db && db+1!=ans.size()) {
            baj=1;
        }
        if (baj) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans;
            for (int i=0; i<c; i++) {
                if (!v[i]) {
                    char c='a'+i;
                    cout << c;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}