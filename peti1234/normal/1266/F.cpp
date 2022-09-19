#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, ans[2*c], leut[c];
vector<int> sz[c], t[c];
vector<pair<int, int> > csop[c];
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            t[a].push_back(leut[x]+1);
            leut[a]=max(leut[a], leut[x]+1);
        }
    }
}
void dfs2(int a) {
    sort(t[a].begin(), t[a].end());
    for (int x:t[a]) {
        if (csop[a].size()==0 || x!=csop[a].back().first) {
            csop[a].push_back({x, 1});
        } else {
            csop[a].back().second++;
        }
    }
    int si=csop[a].size(), sum=0;
    for (int i=si-1; i>=0; i--) {
        int fi=csop[a][i].first, se=csop[a][i].second;
        sum+=se;
        ans[2*fi-1]=max(ans[2*fi-1], sum);
        ans[2*fi]=max(ans[2*fi], sum);
        if (i>0) {
            int el=csop[a][i-1].first;
            ans[2*el+1]=max(ans[2*el+1], sum+1);
        }
    }
    int opt=csop[a].back().first, opt2=0;
    if (csop[a].back().second>1) {
        opt2=opt;
    } else {
        if (si>1) {
            opt2=csop[a][si-2].first;
        }
    }
    v2[a]=true;
    for (int x:sz[a]) {
        if (!v2[x]) {
            if (leut[x]+1==opt) {
                t[x].push_back(opt2+1);
            } else {
                t[x].push_back(opt+1);
            }
            dfs2(x);
            int p1=csop[a].size(), p2=csop[x].size();
            p1--, p2--;
            sum=-2;
            bool spec=(a==1 && x==4);
            while (p1>=0 || p2>=0) {
                if (p2<0 || (p1>=0 && csop[a][p1].first>=csop[x][p2].first)) {
                    int s=csop[a][p1].first;
                    sum+=csop[a][p1].second;
                    p1--;
                    ans[2*s]=max(ans[2*s], sum);
                } else {
                    int s=csop[x][p2].first;
                    sum+=csop[x][p2].second;
                    p2--;
                    ans[2*s]=max(ans[2*s], sum);
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        int s=sz[i].size();
        ans[1]=max(ans[1], s+1);
    }
    dfs(1);
    dfs2(1);
    for (int i=n; i>=1; i--) {
        ans[i]=max({1, ans[i], ans[i+2]});
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}