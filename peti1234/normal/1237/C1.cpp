#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int, int>, pair<int, int> > > v;
int el[50003];
int kov[50003];
bool p[50001];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, {c, i}});
    }
    for (int i=0; i<n; i++) {
        el[i]=i-1;
        kov[i]=i+1;
    }
    sort(v.begin(), v.end());
    for (int i=1; i<n; i++) {
        if (el[i]>=0) {
            int a=el[i];
            if (v[i].first.first==v[a].first.first && v[i].first.second==v[a].first.second) {
                int x=v[i].second.second;
                int y=v[a].second.second;
                cout << x << " " << y << "\n";
                p[i]=true;
                p[a]=true;
                el[kov[i]]=el[a];
                kov[el[a]]=kov[i];
            }
        }
    }
    for (int i=1; i<n; i++) {
        if (el[i]>=0) {
            int a=el[i];
            if (!p[i] && v[i].first.first==v[a].first.first) {
                int x=v[i].second.second;
                int y=v[a].second.second;
                cout << x << " " << y << "\n";
                p[i]=true;
                p[a]=true;
                el[kov[i]]=el[a];
                kov[el[a]]=kov[i];
            }
        }
    }
    for (int i=1; i<n; i++) {
        if (el[i]>=0) {
            int a=el[i];
            if (!p[i]) {
                int x=v[i].second.second;
                int y=v[a].second.second;
                cout << x << " " << y << "\n";
                p[i]=true;
                p[a]=true;
                el[kov[i]]=el[a];
                kov[el[a]]=kov[i];
            }
        }
    }
    return 0;
}