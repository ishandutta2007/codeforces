#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, comp[c], cnt;
long long lo, hi=2e9+1, mid, t[c][c], x[c], y[c];
vector<pair<pair<int, int>, int> > xr, yr;
vector<pair<int, int> > el;
vector<int> sz[c], s[c];
bool v[c];
void add(int a, int b, int c) {
    sz[a].push_back(b), s[a].push_back(c), sz[b].push_back(a), s[b].push_back(c), el.push_back({a, b});
}
void dfs(int a) {
    v[a]=1, comp[a]=cnt;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x] && y<=mid) dfs(x);
    }
}
bool k(int a, int b, int c) {
    long long z=t[a][b], x=t[a][c], y=t[b][c];
    return (comp[a]!=comp[c] && comp[b]!=comp[c] && x+y-z<=2*mid && z+(abs(x-y))<=2*mid);
}
bool jo() {
    bool ans=0; cnt=0;
    for (int i=1; i<=n; i++) v[i]=0;
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cnt++;
            dfs(i);
        }
    }
    if (cnt==1) ans=1;;
    if (cnt==2) {
        for(int i=1; i<=n; i++) {
            for (int i=0; i<el.size(); i++) {
                int a=el[i].first, b=el[i].second;
                if (comp[a]!=comp[b] && t[a][b]<=2*mid) ans=1;
            }
            for (int j=1; j<=n; j++) {
                if (comp[i]!=comp[j] && mid>=max(abs(x[i]-x[j]), abs(y[i]-y[j]))) ans=1;
            }
        }
    }
    if (cnt==3 || cnt==4) {
        for (int i=0; i<el.size(); i++) {
            int a=el[i].first, b=el[i].second;
            if (comp[a]!=comp[b]) {
                if (cnt==3) {
                    for (int j=1; j<=n; j++) {
                        if (k(a, b, j)) ans=1;
                    }
                } else {
                    for (int j=0; j<el.size(); j++) {
                        int c=el[j].first, d=el[j].second;
                        if (comp[c]!=comp[d] && k(a, b, c) && k(a, b, d)) ans=1;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        xr.push_back({{x[i], y[i]}, i}), yr.push_back({{y[i], x[i]}, i});
    }
    sort(xr.begin(), xr.end()), sort(yr.begin(), yr.end());
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            t[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
        }
    }
    for (int i=1; i<n; i++) {
        if (xr[i].first.first==xr[i-1].first.first) {
            int a=xr[i-1].second, b=xr[i].second, tav=xr[i].first.second-xr[i-1].first.second;
            add(a, b, tav);
        }
        if (yr[i].first.first==yr[i-1].first.first) {
            int a=yr[i-1].second, b=yr[i].second, tav=yr[i].first.second-yr[i-1].first.second;
            add(a, b, tav);
        }
    }
    while(hi-lo>1) {
        mid=(hi+lo)/2;
        if (jo()) hi=mid;
        else lo=mid;
    }
    if (hi==2e9+1) hi=-1;
    cout << hi << "\n";
    return 0;
}