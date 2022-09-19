#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long n, m, tav[c];
vector<pair<int, int> > sz[c];
priority_queue<pair<long long, int> > q;
bool v[c];
void add(int a, int b, int c) {
    sz[a].push_back({b, c});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        add(i, i+n, 0);
    }
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b+n, a+n, c);
    }
    q.push({0, 1});
    while (q.size()>0) {
        long long a=q.top().second, dist=-q.top().first;
        q.pop();
        if (v[a]) continue;
        v[a]=true, tav[a]=dist;
        for (auto p:sz[a]) {
            int x=p.first;
            long long y=dist+p.second;
            if (!v[x]) {
                q.push({-y, x});
            }
        }
    }
    for (int i=n+2; i<=2*n; i++) {
        cout << (v[i] ? tav[i] : -1) << " ";
    }
    cout << "\n";
    return 0;
}