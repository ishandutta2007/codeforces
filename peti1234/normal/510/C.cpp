#include <bits/stdc++.h>

using namespace std;
const int c=26;
vector<int> sz[c];
int be[c], v[c], n, pr;
string sol, s, el;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> el;
    for (int i=1; i<n; i++) {
        cin >> s;
        int mini=min(s.size(), el.size());
        for (int i=0; i<mini; i++) {
            if (s[i]!=el[i]) {
                int x=el[i]-'a', y=s[i]-'a';
                be[y]++, sz[x].push_back(y);
                break;
            }
            if (i+1==mini) {
                if (s.size()==mini) pr=1;
            }
        }
        el=s;
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            if (!be[j] && !v[j]) {
                for (int k=0; k<sz[j].size(); k++) be[sz[j][k]]--;
                v[j]=1;
                sol.push_back((char)'a'+j);
            }
        }
    }
    if (sol.size()<26 || pr) cout << "Impossible\n";
    else cout << sol << "\n";
    return 0;
}