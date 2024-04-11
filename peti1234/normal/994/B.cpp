#include <bits/stdc++.h>

using namespace std;
long long t[100001];
int c[100001];
int n, m;
vector<pair<int, int> > v;
vector<int> k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        int x=v[i].second;
        int y=v[i].first;
        long long p=0;
        for (int i=0; i<k.size(); i++) {
            p-=k[i];
        }
        p+=c[x];
        t[x]=p;
        k.push_back(-c[x]);
        sort(k.begin(), k.end());
        if (k.size()>m) {
            k.pop_back();
        }
    }
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    return 0;
}