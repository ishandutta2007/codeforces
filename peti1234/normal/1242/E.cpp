#include <bits/stdc++.h>

using namespace std;
int n, cnt, kov;
vector<pair<int, int> > sz;
vector<int> sol[100002], p;
void pb() {p.pop_back();}
void add(int a, int b) {sol[a].push_back(b);}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) { int x; cin >> x; sz.push_back({x, i});}
    sort(sz.rbegin(), sz.rend());
    for (int i=1; i<=sz[0].first; i++) cnt++, p.push_back(i), add(sz[0].second, i);
    for (int i=1; i<n; i++) {
        if (i==n-1) kov=2;
        else kov=sz[i+1].first;
        int fi=sz[i].first, se=sz[i].second, si=p.size(), ut=p.back();
        if (fi==3 && si<=4 && kov==3) {
            int q=sz[i+1].second;
            pb(), add(se, p.back()), add(q, p.back()), pb(), add(se, p.back()), cnt++, add(se, cnt), add(q, cnt);
            p.push_back(cnt), p.push_back(ut), add(q, ut), i++;
        } else {
            if (si==4 && kov==4) kov--;
            fi--;
            while(fi>0 && si+fi>kov+1) add(se, p.back()), pb(), si--, fi--;
            add(se, p.back());
            while(fi>0) cnt++, add(se, cnt), p.push_back(cnt), fi--;
            p.push_back(ut);
        }
    }
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) {
        for (int j=0; j<sol[i].size(); j++) cout << sol[i][j] << " ";
        cout << "\n";
    }
    return 0;
}