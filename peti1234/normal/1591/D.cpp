#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, t[c], s[c], kor;
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (!v[t[a]]) {
        dfs(t[a]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        bool jo=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (s[t[i]]) jo=1;
            s[t[i]]=1;
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                kor++;
                dfs(i);
            }
        }
        cout << (((n-kor)%2 && !jo) ? "NO" : "YES") << "\n";
        for (int i=1; i<=n; i++) v[i]=0, s[i]=0;
        kor=0;
    }
    return 0;
}