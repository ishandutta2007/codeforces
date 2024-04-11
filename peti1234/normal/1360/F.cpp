#include <bits/stdc++.h>

using namespace std;
string t[11];
string s;
int n, m, jo, w;
void ch() {
    for (int i=1; i<=n; i++) {
        int cnt=0;
        for (int j=0; j<m; j++) cnt+=t[i][j]!=s[j];
        if (cnt>1) return;
    }
    cout << s << endl;
    jo=true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, jo=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        s=t[1];
        ch();
        for (int i=0; i<m; i++) for (int j=0; j<26; j++) {
            s=t[1]; s[i]='a'+j;
            if (!jo) ch();
        }
        if (!jo) cout << -1 << "\n";
    }
    return 0;
}