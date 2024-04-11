#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, t[c], ans[c];
bool v[c];
vector<int> kor[c];
vector<int> s;
void dfs(int a) {
    v[a]=true;
    s.push_back(a);
    if (!v[t[a]]) {
        dfs(t[a]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
            int si=s.size();
            if (si%2) {
                int pos=0;
                for (int j=0; j<si; j++) {
                    int kov=(pos+(si+1)/2)%si;
                    ans[s[pos]]=s[kov];
                    pos=kov;
                }
            } else {
                if (kor[si].size()>0) {
                    for (int j=0; j<si; j++) {
                        int kov=(j+1)%si;
                        ans[s[j]]=kor[si][j];
                        ans[kor[si][j]]=s[kov];
                    }
                    kor[si].clear();
                } else {
                    kor[si]=s;
                }
            }
            s.clear();
        }
    }

    for (int i=1; i<=n; i++) {
        if (!ans[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
5
2 3 4 5 1
*/