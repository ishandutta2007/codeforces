#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
vector<long long> sz[100001];
vector<long long> s[100001];
vector<int> sp;
bool v[100001];
long long a=0, b=1000000001;
bool ker(long long x)
{

    queue<long long> q;
    q.push(sp[0]);
    for (int i=1; i<=n; i++) {
        v[i]=false;
    }
    while(q.size()>0) {
        long long f=q.front();
        q.pop();
        if (!v[f]) {
            v[f]=true;
            for (int i=0; i<sz[f].size(); i++) {
                int y=sz[f][i];
                if (!v[y] && s[f][i]<=x) {
                    q.push(y);
                }
            }
        }
    }
    for (int i=0; i<sp.size(); i++) {
        if (!v[sp[i]]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        int p;
        cin >> p;
        sp.push_back(p);
    }
    for (int i=1; i<=m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b);
        sz[b].push_back(a);
        s[a].push_back(c);
        s[b].push_back(c);
    }
    while(b-a>1) {
        long long c=(b+a)/2;
        if (ker(c)) {
            b=c;
        } else {
            a=c;
        }
    }
    for (int i=1; i<=k; i++) {
        cout << b << " ";
    }
    return 0;
}