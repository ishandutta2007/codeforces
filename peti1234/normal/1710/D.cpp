#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int w, n, veg[c], kezd[c];
bool v[c][c];
vector<pair<int, int> > ans;
void add(int a, int b) {
    ans.push_back({a, b});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            kezd[i]=veg[i]=i;
        }
        for (int i=1; i<=n; i++) {
            for (int j=i; j<=n; j++) {
                char c;
                cin >> c;
                v[i][j]=(c=='1');
            }
        }
        for (int j=1; j<=n; j++) {
            for (int i=j-1; i>=1; i--) {
                if (v[i][j]) {
                    if (veg[i]>=kezd[j]) {
                        veg[i]=j, kezd[j]=i;
                        continue;
                    }
                    vector<pair<int, int> > p;
                    int pos=i;
                    while (pos<=j) {
                        p.push_back({pos, veg[pos]});
                        pos=veg[pos]+1;
                    }
                    int si=p.size();
                    if (si==2) {
                        add(p[0].first, p[1].second);
                    }
                    if (si==3) {
                        add(p[0].first, p[2].second);
                        if (p[1].second-p[0].first>1) {
                            add(p[0].first, p[1].second);
                        } else {
                            add(p[1].first, p[2].second);
                        }
                    }
                    if (si>=4) {
                        add(p[0].first, p[si-1].second);
                        add(p[1].first, p[si-1].second);
                        for (int i=2; i<si-1; i++) {
                            add(p[0].first, p[i].first);
                        }

                    }
                    veg[i]=j, kezd[j]=i;
                }
            }
        }
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
        ans.clear();
    }
    return 0;
}