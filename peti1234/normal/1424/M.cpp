#include <bits/stdc++.h>

using namespace std;
const int c=26;
vector<int> sz[c];
int be[c], v[c], n, pr, k, p, l[c], ldb;
vector<string> x[1002];
string sol, s, el;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> p;
        for (int i=0; i<k; i++) {
            cin >> s;
            x[p].push_back(s);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            s=x[i][j];
            int mini=min(s.size(), el.size());
            for (int i=0; i<mini; i++) {
                if (s[i]!=el[i]) {
                    int x=el[i]-'a', y=s[i]-'a';
                    be[y]++, sz[x].push_back(y);
                    break;
                }
                if (i+1==mini) {
                    if (s.size()==mini && s!=el) pr=1;
                }
            }
            el=s;
            for (int i=0; i<s.size(); i++) if (!l[s[i]-'a']) ldb++, l[s[i]-'a']=1;
        }
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            if (!be[j] && !v[j] && l[j]) {
                for (int k=0; k<sz[j].size(); k++) be[sz[j][k]]--;
                v[j]=1;
                sol.push_back((char)'a'+j);
            }
        }
    }
    if (sol.size()<ldb || pr) cout << "IMPOSSIBLE\n";
    else cout << sol << "\n";
    return 0;
}