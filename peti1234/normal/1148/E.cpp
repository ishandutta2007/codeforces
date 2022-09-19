#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int> > s;
vector<int> f;
long long sum;
vector<pair<int, pair<int, int >> > pl;
vector<pair<int, pair<int, int> > > mi;
vector<pair<pair<int, int>, int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        sum+=a;
        s.push_back({a, i});
    }
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        sum-=a;
        f.push_back(a);
    }
    if (sum!=0) {
        cout << "NO" << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    sort(f.begin(), f.end());
    for (int i=0; i<n; i++) {
        int x=s[i].first;
        int y=s[i].second;
        int z=f[i];
        if (x-z<0) {
            pl.push_back({z-x,{y, x}});
        }
        if (x-z>0) {
            mi.push_back({x-z, {y, x}});
        }
    }
    while(pl.size()>0) {
        while(pl.size()>0 && pl.back().first==0) {
            pl.pop_back();
        }
        if (pl.size()==0) {
            break;
        }
        while(mi.back().first==0) {
            mi.pop_back();
        }
        int a=pl.back().first;
        int b=pl.back().second.first;
        int c=mi.back().first;
        int d=mi.back().second.first;
        int e=min(a, c);
        if (pl.back().second.second>mi.back().second.second) {
            cout << "NO";
            return 0;
        }
        pl.back().second.second+=e;
        mi.back().second.second-=e;
        ans.push_back({{b, d}, e});
        pl.back().first-=e;
        mi.back().first-=e;
    }
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
    }
    return 0;
}