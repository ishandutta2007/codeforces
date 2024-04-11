#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, fel[c], le[c], tav[c];
bool v[c];
pair<int, int> lep[c];
set<int> s;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> fel[i];
    for (int i=1; i<=n; i++) cin >> le[i];
    for (int i=0; i<=n+1; i++) s.insert(i);
    q.push(n);
    v[n]=1;
    while (q.size()>0) {
        int id=q.front();
        q.pop();

        auto it=s.lower_bound(id-fel[id]);
        while (*it<=id) {
            int kov=*it+le[*it];
            if (!v[kov]) {
                v[kov]=1;
                tav[kov]=tav[id]+1;
                lep[kov]={id, *it};
                q.push(kov);
            }
            auto it2=it;
            it++;
            s.erase(it2);
        }
    }
    if (!v[0]) {
        cout << -1 << "\n";
    } else {
        cout << tav[0] << "\n";
        vector<int> ans;
        int pos=0;
        while (pos!=n) {
            ans.push_back(lep[pos].second);
            pos=lep[pos].first;
        }
        reverse(ans.begin(), ans.end());
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}