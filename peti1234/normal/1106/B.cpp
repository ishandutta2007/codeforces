#include <bits/stdc++.h>

using namespace std;
int n, m;
long long r[100001];
long long c[100001];
bool v[100001];
priority_queue<pair<long long, pair <long long, int> > >q;
long long solve(long long b)
{

    long long sum=0;
    if (b==0) {
        return 0;
    }
    if (q.size()==0) {
        return 0;
    }
    int fi=q.top().first;
    int sefi=q.top().second.first;
    int sese=q.top().second.second;
    sese*=-1;
    if (v[sese]) {
        q.pop();
        return solve(b);
    }
    long long y=min(r[sese], b);
    b-=y;
    sum+=-fi*y;
    r[sese]-=y;
    if (b>0) {
        q.pop();
        sum+=solve(b);
        return sum;
    }
    q.push({fi, {-y, -sese}});
    return sum;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> r[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        q.push({-c[i], {-r[i], -i}});
    }
    for (int i=1; i<=m; i++) {
        long long a, b;
        cin >> a >> b;
        long long sum=0;
        int y=min(b, r[a]);
        b-=y;
        q.push({-c[a], {-b, -a}});
        sum+=c[a]*y;
        r[a]-=y;
        sum+=solve(b);
        while(q.size()>0 && q.top().first==0) {
            q.pop();
        }
        if (b>0 && q.size()==0) {
            sum=0;
        }
        cout << sum << " ";
    }

    return 0;
}