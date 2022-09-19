#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > sz, vi;
priority_queue<pair<int, int> > q;
int n, sum, db;
int r;
int f[500001];
int holvan(int a)
{
    int x=f[a];
    if (!x) return a;
    f[a]=holvan(x);
    return f[a];
}
void unio(int a, int b)
{
    a=holvan(a), b=holvan(b);
    if (a!=b) f[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, b});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int fi=sz[i].first, se=sz[i].second;
        while(q.size()>0 && fi>-q.top().first) q.pop();
        while(q.size()>0 && se>-q.top().first) {
            unio(i+1, q.top().second);
            vi.push_back({q.top().first, q.top().second});
            q.pop();
            db++;
            if (db>=i+1) {
                cout << "NO";
                return 0;
            }
        }
        for(int i=0; i<vi.size(); i++) q.push({vi[i].first, vi[i].second});
        vi.clear();
        q.push({-se, i+1});
    }
    for (int i=2; i<=n; i++) if (holvan(i)!=holvan(1)){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}